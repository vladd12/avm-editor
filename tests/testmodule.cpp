#include "testmodule.h"

#include <avm-editor/database/database.hpp>

TestModule::TestModule(QObject *parent) : QObject(parent)
{
}

void TestModule::testOne()
{
    auto dbPtr = avm::createDatabase("test.db", this);
    dbPtr->createTable("test", "id INTEGER PRIMARY KEY, value TEXT");
    QVERIFY(true);
}

void TestModule::testTwo()
{
    ;
}

QTEST_GUILESS_MAIN(TestModule)
