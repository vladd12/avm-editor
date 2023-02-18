#pragma once

#include <QString>

namespace detail
{

bool createFileInCurrentPath(const QString &filename) noexcept;
QString getFullPath(const QString &filename) noexcept;

} // namespace detail
