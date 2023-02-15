#pragma once

#include <avm-editor/core/core.hpp>

namespace avm {
// Forward declaration of Database class
class Database;

/// \brief Class of database's table
class libapi Table
{
private:
    Database *m_Parent;
    QString m_Name;

    const bool isParentExist() const noexcept;
    void printErrorMessage() const noexcept;

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

    void select(const QString &columns) const noexcept;
    void select(const QString &columns, const QString &where) const noexcept;
    void insert(const QString &values) noexcept;
};

} // namespace avm
