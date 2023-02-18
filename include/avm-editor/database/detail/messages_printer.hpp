#pragma once

#include <QString>
#include <SQLiteCpp/Exception.h>

namespace detail
{

/// \brief Function for printing error message of exception was thrown.
void printExceptionMessage(const SQLite::Exception &ex) noexcept;

/// \brief Function for printing error message about
/// non-existing parent member in Database::Table class.
void printTableErrorMessage(const QString &tableName) noexcept;

} // namespace detail
