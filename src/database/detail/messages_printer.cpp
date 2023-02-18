#include <QDebug>
#include <QtGlobal>
#include <avm-editor/database/detail/messages_printer.hpp>

namespace detail
{

void printExceptionMessage(const SQLite::Exception &ex) noexcept
{
    /// TODO: Show more information about SQLite exception.
    qCritical() << "Error: " << ex.what();
}

void printTableErrorMessage(const QString &tableName) noexcept
{
    qCritical() << "Parent database for table " << tableName << " doesn't exist!";
}

} // namespace detail
