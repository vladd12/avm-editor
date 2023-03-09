#include <avm-editor/database/datatuple.hpp>

namespace avm
{

DataTuple::DataTuple(const SQLite::Column &column) noexcept : data { detail::packDataCell(column) }
{
}

DataTuple::DataTuple(const DataTuple &rhs) noexcept : data(rhs.data)
{
}

DataTuple::DataTuple(const DataTuple &&rhs) noexcept : data(std::move(rhs.data))
{
}

void DataTuple::append(const SQLite::Column &column) noexcept
{
    data.append(detail::packDataCell(column));
}

}
