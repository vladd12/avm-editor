#pragma once

#include <QObject>
#include <QtTest>

class TestModule : public QObject
{
    Q_OBJECT
public:
    explicit TestModule(QObject *parent = nullptr);
private slots:
    /// \brief Вызывается перед первой тестовой функцией
    void initTestCase()
    {
    }

    /// \brief Вызывается перед каждой тестовой функцией
    void init()
    {
    }

    /// \brief Вызывается после каждой тестовой функции
    void cleanup()
    {
    }

    /// \brief Вызывается после последней тестовой функции
    void cleanupTestCase()
    {
    }

    void testOne();
    void testTwo();
};
