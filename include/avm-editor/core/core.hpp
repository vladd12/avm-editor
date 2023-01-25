#pragma once

#include <avm-editor/core/config.hpp>
#include <QObject>

namespace avm {

struct QDeleter
{
    void operator()(QObject *obj) const
    {
        if (obj)
            obj->deleteLater();
    }
};

template<typename T> //
using QUniquePtr = std::unique_ptr<T, QDeleter>;

libapi void foo();

} // namespace avm
