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

bool Table::verify() const noexcept
{
    return isParentExist();
}

void Table::select(const QString &columns, const QString &where) const noexcept
{
    if (isParentExist())
    {
        auto query = QString("SELECT %1 FROM %2").arg(columns, m_Name);
        if (where.length() > 0)
            query += QString(" WHERE %1").arg(where);
        try
        {
            auto stdQuery = query.toStdString();
            SQLite::Statement stm(m_Parent->m_db, stdQuery.c_str());
            selectRowsParse(stm);
        } catch (const SQLite::Exception &ex)
        {
            qCritical(ex.what());
        }
    }
    else
        detail::printTableErrorMessage(m_Name);
}

void Table::selectRowsParse(SQLite::Statement &stm) const
{
    while (stm.executeStep())
    {
        selectColumnsParse(stm);
    }
}

void Table::selectColumnsParse(SQLite::Statement &stm) const
{
    auto colCount = stm.getColumnCount();
    for (int i = 0; i < colCount; i++)
    {
        std::string colName(stm.getColumnName(i));
        std::string colData(stm.getColumnDeclaredType(i));
        auto col = stm.getColumn(i);
    }
}

bool Table::insert(const QString &values) noexcept
{
    if (isParentExist())
    {
        QString query = "INSERT INTO %1 VALUES (%2)";
        query = query.arg(m_Name, values);
        auto stdQuery = query.toStdString();
        try
        {
            m_Parent->m_db.exec(stdQuery.c_str());
            return true;
        } catch (const SQLite::Exception &ex)
        {
            qCritical(ex.what());
            return false;
        }
    }
    else
        detail::printTableErrorMessage(m_Name);
    return false;
}

} // namespace avm
