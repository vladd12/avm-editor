#pragma once

#include <QList>
#include <SQLiteCpp/Column.h>
#include <avm-editor/core/core.hpp>
#include <cstdint>
#include <variant>

namespace avm
{
using DataCell = std::variant<std::int32_t, std::int64_t, double, const char *, const void *>;

DataCell libapi packDataCell(const SQLite::Column &column) noexcept;

void libapi unpackDataCell() noexcept;

class libapi DataTuple
{
public:
private:
    QList<DataCell> data;

public:
    explicit DataTuple() noexcept;
};

}
