#include "mainwindow.h"

#include <QMessageBox>
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    try
    {
        // Open a database file
        SQLite::Database db("test.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE, 10);
        // Compile a SQL query, containing one parameter (index 1)
        SQLite::Statement query(db, "SELECT * FROM test WHERE size > ?");
        // Bind the integer value 6 to the first parameter of the SQL query
        query.bind(1, 6);
        // Loop to execute the query step by step, to get rows of result
        while (query.executeStep())
        {
            // Demonstrate how to get some typed column value
            auto id = query.getColumn(0);
            auto value = query.getColumn(1);
            auto size = query.getColumn(2);
            std::cout << "row: " << id << ", " << value << ", " << size << "\n";
        }
    } catch (const SQLite::Exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());
    }
}

MainWindow::~MainWindow()
{
}
