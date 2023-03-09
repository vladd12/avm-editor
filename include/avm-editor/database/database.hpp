#pragma once

#include <SQLiteCpp/Database.h>
#include <avm-editor/core/core.hpp>
#include <avm-editor/database/table.hpp>

namespace avm
{
/// \brief Class of database.
class libapi Database : public QObject
{
    Q_OBJECT
private:
    SQLite::Database m_db;
    friend class Table;

public:
    /// \brief Parametric c-tor.
    explicit Database(const std::string &filepath, const int flags, const int timeout, QObject *parent = nullptr);

    /// \brief Creating table query to the database.
    Table createTable(const QString &tableName, const QString &schema);

    /// \brief Getting existing table from the database.
    Table getTable(const QString &tableName);

    /// \brief Removing existing table from the database.
    void dropTable(const QString &tableName);
};

/// \brief Creating a new database in the specified filepath.
/// \details If the file already exists at the specified filepath,
/// then returns Database object of the existing database. If any
/// exception is raised in Database object's c-tor, then returns nullptr.
/// \see openDatabase
libapi QUniquePtr<Database> createDatabase( //
    const QString &filepath, QObject *parent = nullptr) noexcept;

/// \brief Openning the exisiting database in the specifie filepath.
/// \details If the file doen't exists at the specified filepath,
/// then an exception is raised and returns nullptr.
/// \see createDatabase
libapi QUniquePtr<Database> openDatabase( //
    const QString &filepath, QObject *parent = nullptr) noexcept;

} // namespace avm
