#pragma once

#include <QList>
#include <avm-editor/core/core.hpp>
#include <variant>

namespace avm
{

class libapi DataTuple
{
public:
    using CellType = std::variant<std::string, int, float, double>;

private:
    QList<CellType> data;

public:
    explicit DataTuple() noexcept;
};

}
