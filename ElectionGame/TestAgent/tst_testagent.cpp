#include "agent.h"
#include "location.h"

#include <QSignalSpy>
#include <QtTest>

class TestAgent : public QObject
{
    Q_OBJECT

public:
    TestAgent();

private Q_SLOTS:
    void nameTest_data();
    void nameTest();
};

TestAgent::TestAgent()
{
}
void TestAgent::nameTest_data(){
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");

    QTest::newRow("Normi") << "Apina" << "Apina";
    QTest::newRow("Oudot kirjaimet") << "€éḿþy" << "€éḿþy";
    QTest::newRow("Pitkä") << "AbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyz" << "AbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyzAbcdefghijklmnopqrstuvwxyz";

}
void TestAgent::nameTest(){
    QFETCH(QString, input);
    QFETCH(QString, result);
    Agent* agentti = new Agent(input,0);
    QCOMPARE(agentti->name(), result);
    delete agentti;
}


QTEST_APPLESS_MAIN(TestAgent)

#include "tst_testagent.moc"
