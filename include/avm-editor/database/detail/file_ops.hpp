#pragma once

#include <QString>

namespace detail
{

/// \brief Creates file specified by the filename
/// in the current working path.
bool createFileInCurrentPath(const QString &filename) noexcept;

/// \brief Returns a full path to the file specified
/// by the filename in the current working path.
QString getFullPath(const QString &filename) noexcept;

} // namespace detail
