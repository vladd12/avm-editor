#include <avm-editor/database/database.hpp>
#include <avm-editor/database/detail/messages_printer.hpp>
#include <avm-editor/database/table.hpp>

namespace avm
{

Table::Table() noexcept : m_Parent(nullptr), m_Name("")
{
}

Table::Table(Database *parent, const QString &tableName) noexcept : m_Parent(parent), m_Name(tableName)
{
}

const bool Table::isParentExist() const noexcept
{
    return m_Parent != nullptr;
}

void Table::select(const QString &columns) const noexcept
{
    if (isParentExist())
    {
        ;
    }
    else
        detail::printTableErrorMessage(m_Name);
}

void Table::select(const QString &columns, const QString &where) const noexcept
{
    if (isParentExist())
    {
        ;
    }
    else
        detail::printTableErrorMessage(m_Name);
}

void Table::insert(const QString &values) noexcept
{
    if (isParentExist())
    {
        QString query = "INSERT INTO %1 VALUES (%2)";
        query = query.arg(m_Name, values);
        auto stdQuery = query.toStdString();
        try
        {
            m_Parent->m_db.exec(stdQuery.c_str());
        } catch (const SQLite::Exception &ex)
        {
            qCritical(ex.what());
        }
    }
    else
        detail::printTableErrorMessage(m_Name);
}

} // namespace avm
