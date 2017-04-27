#include "agent.h"
#include "location.h"

#include <QSignalSpy>
#include <QtTest>
#include <vector>

class TestAgent : public QObject
{
    Q_OBJECT

public:
    TestAgent();

private Q_SLOTS:
    void commonTest_data();
    void commonTest();
    void nameTest_data();
    void nameTest();
    void locationTest_data();
    void locationTest();
    void typeTest();

private:
    std::vector<Interface::Location*> lokaatiot_;
    std::vector<std::shared_ptr <Interface::Location> > loka2_;
};

TestAgent::TestAgent()
{
}

void TestAgent::commonTest_data()
{
    QTest::addColumn<QString>("nimi");
    QTest::addColumn<bool>("common");
    QTest::addColumn<bool>("result");

    QTest::newRow("Eicommon") << "Apina" << false << false;
    QTest::newRow("Kylcommon") << "Apina" << true << true;
}

void TestAgent::commonTest()
{
    QFETCH(QString, nimi);
    QFETCH(bool, common);
    QFETCH(bool, result);
    Agent* agentti = new Agent(nimi, common);
    QCOMPARE(agentti->isCommon(), result);
    delete agentti;

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

void TestAgent::locationTest_data()
{
    std::vector<QString> nimet {"Pääsisäismaa", "Joulujallutähti", "Kermaiset kulmakuuma kundiukot", "Hengenpelastajatytöt", "Metsä miähet", "Hörökorvapuustit", "Salmiakki_on_hyvää", "Suklaamyös"};
    for(unsigned int i = 0; i < 8; ++i){
        Interface::Location* location = new Interface::Location(i, nimet.at(i));
        std::shared_ptr<Interface::Location> lk = std::make_shared<Interface::Location>(i, nimet.at(i));
        lokaatiot_.push_back(location);
    }
    QTest::addColumn<QString>("agentinnimi");
    QTest::addColumn<Interface::Location*>("Lokaatio");

    QTest::newRow("Eka") << "Apina" << lokaatiot_.at(0);
    QTest::newRow("Toka") << "Apina" << lokaatiot_.at(1);
    QTest::newRow("Kolmas") << "Apina" << lokaatiot_.at(2);
    QTest::newRow("Neljas") << "Apina" << lokaatiot_.at(3);
    QTest::newRow("Viides") << "Apina" << lokaatiot_.at(4);
    QTest::newRow("Kuudes") << "Apina" << lokaatiot_.at(5);
    QTest::newRow("Seitsemäs") << "Apina" << lokaatiot_.at(6);
    QTest::newRow("Kahdeksas") << "Apina" << lokaatiot_.at(7);
}

void TestAgent::locationTest()
{
    QFETCH(QString, nimi);
    QFETCH(Interface::Location*, lokaatio);

    Agent* agentti = new Agent(nimi,false);
    std::shared_ptr<Interface::Location> location = std::make_shared<Interface::Location>(*lokaatio);
    agentti->setPlacement(location);
}

void TestAgent::typeTest()
{
    Agent* agentti  = new Agent(QString {"Apina"},0);
    QString* tyyppi = new QString("Agent");
    QCOMPARE(agentti->typeName(), *tyyppi);
    delete agentti;
    delete tyyppi;
}


QTEST_APPLESS_MAIN(TestAgent)

#include "tst_testagent.moc"
