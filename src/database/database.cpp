#include <QFile>
#include <avm-editor/database/database.hpp>
#include <avm-editor/database/detail/messages_printer.hpp>

namespace avm
{

Database::Database(const std::string &filepath, const int flags, const int timeout, QObject *parent)
    : QObject(parent), m_db(filepath, flags, timeout)
{
}

Table Database::createTable(const QString &tableName, const QString &schema) noexcept
{
    auto query = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + schema + ")";
    try
    {
        m_db.exec(query.toStdString());
        return Table(this, tableName);
    } catch (const SQLite::Exception &e)
    {
        detail::printExceptionMessage(e);
        return Table();
    }
}

Table Database::getTable(const QString &tableName) noexcept
{
    try
    {
        if (m_db.tableExists(tableName.toStdString()))
            return Table(this, tableName);
        else
            return Table();
    } catch (const SQLite::Exception &e)
    {
        detail::printExceptionMessage(e);
        return Table();
    }
}

void Database::dropTable(const QString &tableName) noexcept
{
    auto query = "DROP TABLE IF EXISTS " + tableName;
    try
    {
        m_db.exec(query.toStdString());
    } catch (const SQLite::Exception &e)
    {
        detail::printExceptionMessage(e);
    }
}

QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent) noexcept
{
    try
    {
        auto db = new Database(filepath.toStdString(), SQLite::OPEN_CREATE, 10, parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e)
    {
        detail::printExceptionMessage(e);
        return nullptr;
    }
}

QUniquePtr<Database> openDatabase(const QString &filepath, QObject *parent) noexcept
{
    try
    {
        auto db = new Database(filepath.toStdString(), SQLite::OPEN_READWRITE, 10, parent);
        return QUniquePtr<Database>(db);
    } catch (const SQLite::Exception &e)
    {
        detail::printExceptionMessage(e);
        return nullptr;
    }
}

} // namespace avm
