#include <avm-editor/database/database.hpp>
#include <utility>
#include <QMessageBox>

namespace avm {

Database::Database(SQLite::Database &&db, QObject *parent) : QObject(parent), m_db(std::move(db)) {}

void exceptionMsgPrint(const SQLite::Exception &ex)
{
    qCritical() << "Error: " << ex.what();
}

Table Database::createTable(const QString &tableName, const QString &schema) noexcept
{
    auto query = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + schema + ")";
    try {
        m_db.exec(query.toStdString());
        return Table(this, tableName);
    } catch (const SQLite::Exception &e) {
        exceptionMsgPrint(e);
        return Table();
    }
}

Table Database::getTable(const QString &tableName) noexcept
{
    try {
        if (m_db.tableExists(tableName.toStdString()))
            return Table(this, tableName);
        else
            return Table();
    } catch (const SQLite::Exception &e) {
        exceptionMsgPrint(e);
        return Table();
    }
}

void Database::dropTable(const QString &tableName) noexcept
{
    auto query = "DROP TABLE IF EXISTS " + tableName;
    try {
        m_db.exec(query.toStdString());
    } catch (const SQLite::Exception &e) {
        exceptionMsgPrint(e);
    }
}

QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent) noexcept
{
    try {
        auto sqlDb = SQLite::Database(filepath.toStdString(), SQLite::OPEN_CREATE, 10);
        auto db = new Database(std::move(sqlDb), parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e) {
        exceptionMsgPrint(e);
        return nullptr;
    }
}

QUniquePtr<Database> openDatabase(const QString &filepath, QObject *parent) noexcept
{
    try {
        auto sqlDb = SQLite::Database(filepath.toStdString(), SQLite::OPEN_READWRITE, 10);
        auto db = new Database(std::move(sqlDb), parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e) {
        exceptionMsgPrint(e);
        return nullptr;
    }
}

} // namespace avm
