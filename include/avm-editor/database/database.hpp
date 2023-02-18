#pragma once

#include <SQLiteCpp/Database.h>
#include <avm-editor/core/core.hpp>
#include <avm-editor/database/table.hpp>

namespace avm
{
/// \brief Function for printing error message of exception was thrown.
libapi void printExceptionMessage(const SQLite::Exception &ex);

/// \brief Class of database
class libapi Database : public QObject
{
    Q_OBJECT
private:
    SQLite::Database m_db;
    friend class Table;

public:
    explicit Database(const std::string &filepath, const int flags, const int timeout, QObject *parent = nullptr);

    Table createTable(const QString &tableName, const QString &schema) noexcept;
    Table getTable(const QString &tableName) noexcept;
    void dropTable(const QString &tableName) noexcept;
};

libapi QUniquePtr<Database> createDatabase( //
    const QString &filepath, QObject *parent = nullptr) noexcept;

libapi QUniquePtr<Database> openDatabase( //
    const QString &filepath, QObject *parent = nullptr) noexcept;

} // namespace avm
