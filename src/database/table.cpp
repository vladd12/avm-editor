#include <avm-editor/database/database.hpp>
#include <avm-editor/database/table.hpp>
#include <string>

namespace avm {

Table::Table() noexcept : m_Parent(nullptr), m_Name("") {}

Table::Table(Database *parent, const QString &tableName) noexcept
    : m_Parent(parent), m_Name(tableName)
{}

const bool Table::isParentExist() const noexcept
{
    return m_Parent != nullptr;
}

void Table::printErrorMessage() const noexcept
{
    QString errMsg = "Parent database for table \"%1\" doesn't exist!";
    errMsg = errMsg.arg(m_Name);
    qCritical() << errMsg;
}

void Table::select(const QString &columns) const noexcept
{
    if (isParentExist()) {
        ;
    }
}

void Table::select(const QString &columns, const QString &where) const noexcept
{
    if (isParentExist()) {
        ;
    }
}

void Table::insert(const QString &values) noexcept
{
    if (isParentExist()) {
        QString query = "INSERT INTO %1 VALUES (%2)";
        query = query.arg(m_Name, values);
        auto stdQuery = query.toStdString();
        try {
            m_Parent->m_db.exec(stdQuery.c_str());
        } catch (const SQLite::Exception &ex) {
            qCritical(ex.what());
        }
    } else
        printErrorMessage();
}

} // namespace avm
