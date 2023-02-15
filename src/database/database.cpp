#include <avm-editor/database/database.hpp>
#include <utility>
#include <QMessageBox>

namespace avm {

Database::Database(SQLite::Database &&db, QObject *parent) : QObject(parent), m_db(std::move(db)) {}

Table Database::createTable(const QString &tableName)
{
    return Table();
}

Table Database::getTable(const QString &tableName)
{
    auto stdTableName = tableName.toStdString();
    if (m_db.tableExists(stdTableName.c_str()))
        return Table(this, tableName);
    else
        return Table();
}

void Database::dropTable(const QString &tableName)
{
    ;
}

QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent)
{
    try {
        auto db = new Database(SQLite::Database(filepath.toStdString(), SQLite::OPEN_CREATE, 10),
                               parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e) {
        QMessageBox::critical(nullptr, "Error", e.what());
        return nullptr;
    }
}

QUniquePtr<Database> openDatabase(const QString &filepath, QObject *parent)
{
    try {
        auto db = new Database(SQLite::Database(filepath.toStdString(), SQLite::OPEN_READWRITE, 10),
                               parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e) {
        QMessageBox::critical(nullptr, "Error", e.what());
        return nullptr;
    }
}

} // namespace avm
