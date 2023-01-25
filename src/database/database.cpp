#include <avm-editor/database/database.hpp>
#include <utility>
#include <QMessageBox>

namespace avm {

Database::Database(SQLite::Database &&db, QObject *parent) : QObject(parent), m_db(std::move(db)) {}

QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent)
{
    try {
        auto db = new Database(SQLite::Database(filepath.toStdString(), SQLite::OPEN_CREATE),
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
        auto db = new Database(SQLite::Database(filepath.toStdString(), SQLite::OPEN_READWRITE),
                               parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e) {
        QMessageBox::critical(nullptr, "Error", e.what());
        return nullptr;
    }
}

} // namespace avm
