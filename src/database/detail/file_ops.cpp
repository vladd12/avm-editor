#include <QDir>
#include <QFile>
#include <QTextStream>
#include <avm-editor/database/detail/file_ops.hpp>

bool detail::createFileInCurrentPath(const QString &filename) noexcept
{
    constexpr auto zeroSize = 0;
    auto filepath = QDir::current().filePath(filename);
    QFile newFile(filepath);
    if (newFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream filestream(&newFile);
        filestream << '\n';
        filestream.flush();
        newFile.resize(zeroSize);
        newFile.close();
        return true;
    }
    return false;
}
