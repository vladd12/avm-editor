#include "testmodule.h"

TestModule::TestModule(QObject *parent) : QObject(parent)
{
}

void TestModule::testOne()
{
    ;
}

void TestModule::testTwo()
{
    ;
}

QTEST_GUILESS_MAIN(TestModule)
