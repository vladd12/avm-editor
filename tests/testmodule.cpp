#include "testmodule.h"

#include <avm-editor/database/database.hpp>

TestModule::TestModule(QObject *parent) : QObject(parent)
{
}

void TestModule::testOne()
{
    auto status = false;
    auto dbPtr = avm::createDatabase("test1.db", this);
    status = dbPtr.get() != nullptr;
    QVERIFY(status);
    auto testTable = dbPtr->createTable("test", "id INTEGER PRIMARY KEY, value TEXT");
    status = testTable.verify();
    QVERIFY(status);
    status = testTable.insert("NULL, \"value\"");
    QVERIFY(status);
}

void TestModule::testTwo()
{
    ;
}

QTEST_GUILESS_MAIN(TestModule)
