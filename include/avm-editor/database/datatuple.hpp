#pragma once

#include <QList>
#include <avm-editor/core/core.hpp>
#include <avm-editor/database/detail/datacell.hpp>

namespace avm
{

/// \brief Class for representing a data of
/// the single row in the database's table.
class libapi DataTuple
{
private:
    QList<detail::DataCell> data;

public:
    DataTuple() = default;
    DataTuple &operator=(const DataTuple &rhs) = default;

    /// \brief Parametric c-tor.
    explicit DataTuple(const SQLite::Column &column) noexcept;
    /// \brief Copying c-tor.
    explicit DataTuple(const DataTuple &rhs) noexcept;
    /// \brief Move c-tor.
    explicit DataTuple(const DataTuple &&rhs) noexcept;

    /// \brief Converting column's data to the DataCell
    /// type and append to the current tuple.
    void append(const SQLite::Column &column) noexcept;
};

}
