#include <QDir>
#include <QFile>
#include <QTextStream>
#include <avm-editor/database/detail/file_ops.hpp>

bool detail::createFileInCurrentPath(const QString &filename) noexcept
{
    constexpr auto zeroSize = 0;
    QFile newFile(detail::getFullPath(filename));
    if (!newFile.exists())
    {
        if (newFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream filestream(&newFile);
            filestream << '\n';
            filestream.flush();
            newFile.resize(zeroSize);
            newFile.close();
            return true;
        }
    }
    return false;
}

QString detail::getFullPath(const QString &filename) noexcept
{
    return QDir::current().filePath(filename);
}
