#pragma once

#include <SQLiteCpp/Statement.h>
#include <avm-editor/core/core.hpp>

namespace avm
{
// Forward declaration of Database class
class Database;

/// \brief Class of database's table.
class libapi Table
{
private:
    Database *m_Parent;
    QString m_Name;

    /// \brief Checking that the parent Database object is exist.
    const bool isParentExist() const noexcept;

    void selectRowsParse(SQLite::Statement &stm) const;
    void selectColumnsParse(SQLite::Statement &stm) const;

public:
    /// \brief Default constructor.
    explicit Table() noexcept;

    /// \brief Constructor with params.
    explicit Table(Database *parent, const QString &tableName) noexcept;

    // Table is copyable
    Table(const Table &rhs) = default;
    Table &operator=(const Table &rhs) = default;

    // Database is movable
    Table(Table &&rhs) = default;
    Table &operator=(Table &&rhs) = default;

    /// \brief Verifying table.
    /// \details Checking access to the parent Database object.
    /// \see isParentExist
    bool verify() const noexcept;

    /// \brief Select query to the database.
    void select(const QString &columns, const QString &where = "") const noexcept;

    /// \brief Inserting a data represented by values in the table.
    bool insert(const QString &values) noexcept;
};

} // namespace avm
