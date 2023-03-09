#pragma once

#include <SQLiteCpp/Column.h>
#include <avm-editor/core/core.hpp>
#include <cstdint>
#include <variant>

namespace detail
{
/// \brief DataCell type for storaging integer, float, text and blob data types.
using DataCell = std::variant<std::int32_t, std::int64_t, double, const char *, const void *>;

/// \brief Packing SQLiteCpp Column to DataCell type.
DataCell libapi packDataCell(const SQLite::Column &column) noexcept;

/// TODO:
/// \brief Unpacking DataCell (???).
void libapi unpackDataCell() noexcept;

} // namespace detail
