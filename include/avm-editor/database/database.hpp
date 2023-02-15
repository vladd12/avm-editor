#pragma once

#include <SQLiteCpp/Database.h>
#include <avm-editor/core/core.hpp>
#include <avm-editor/database/table.hpp>

namespace avm {
/// \brief Class of database
class libapi Database : public QObject
{
    Q_OBJECT
private:
    SQLite::Database m_db;
    friend class Table;

public:
    explicit Database(SQLite::Database &&db, QObject *parent = nullptr);
    Table createTable(const QString &tableName);
    Table getTable(const QString &tableName);
    void dropTable(const QString &tableName);
};

libapi QUniquePtr<Database> createDatabase(const QString &filepath, QObject *parent = nullptr);
libapi QUniquePtr<Database> openDatabase(const QString &filepath, QObject *parent = nullptr);

} // namespace avm
