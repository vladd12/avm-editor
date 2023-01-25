#pragma once

#include <SQLiteCpp/Database.h>
#include <avm-editor/core/core.hpp>
#include <QObject>

namespace avm {
/// \brief Database class
class libapi Database : public QObject
{
    Q_OBJECT
private:
    SQLite::Database m_db;

public:
    Database(SQLite::Database &&db, QObject *parent = nullptr);
};

libapi QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent = nullptr);
libapi QUniquePtr<Database> openDatabase(const QString &filepath, QObject *parent = nullptr);

} // namespace avm
