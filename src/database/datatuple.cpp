#include <avm-editor/database/datatuple.hpp>

namespace avm
{

DataCell libapi packDataCell(const SQLite::Column &column) noexcept
{
    if (column.isInteger())
    {
        auto dataSize = column.size();
        if (dataSize == sizeof(std::int32_t))
            return column.getInt();
        else if (dataSize == sizeof(std::int64_t))
            return column.getInt64();
        // Error size for integer, return null
        else
            return static_cast<void *>(nullptr);
    }
    else if (column.isFloat())
        return column.getDouble();
    else if (column.isText())
        return column.getText();
    else if (column.isBlob())
        return column.getBlob();
    // Null and other undefined types
    else
        return static_cast<void *>(nullptr);
}

DataTuple::DataTuple() noexcept
{
}

}
