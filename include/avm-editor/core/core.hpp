#pragma once

#include <QObject>
#include <QString>
#include <avm-editor/core/config.hpp>
#include <memory>

namespace avm
{

struct QDeleter
{
    void operator()(QObject *obj) const
    {
        if (obj)
            obj->deleteLater();
    }
};

template <typename T> //
using QUniquePtr = std::unique_ptr<T, QDeleter>;

libapi void foo();

} // namespace avm
