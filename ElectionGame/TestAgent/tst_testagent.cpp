#include "agent.h"
#include "location.h"
#include "game.h"
#include "player.h"

#include <QSignalSpy>
#include <QtTest>
#include <vector>

Q_DECLARE_METATYPE(std::shared_ptr<Interface::Location>)
Q_DECLARE_METATYPE(std::shared_ptr<Interface::Player>)

class TestAgent : public QObject
{
    Q_OBJECT

public:
    TestAgent();

private Q_SLOTS:
    void commonTest_data();
    void commonTest();
    void connectionTest_data();
    void connectionTest();
    void nameTest_data();
    void nameTest();
    void locationTest_data();
    void locationTest();
    void ownerTest_data();
    void ownerTest();
    void typeTest();

private:
    std::vector<Interface::Location*> lokaatiot_;
    std::shared_ptr<Interface::Game> peli_;
    std::vector<std::shared_ptr<Interface::Player> > nimet_;
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

void TestAgent::connectionTest_data()
{
    QTest::addColumn<QString>("Nimi");
    QTest::addColumn<unsigned short>("Konnektiot");
    QTest::addColumn<unsigned short>("Result");
    std::vector<unsigned short> numerot = {0,1,2,100};

    QTest::newRow("Nolla") << "Apina" << numerot.at(0) << numerot.at(0);
    QTest::newRow("Yksi") << "Apina" << numerot.at(1) << numerot.at(1);
    QTest::newRow("Kaksi") << "Apina" << numerot.at(2) << numerot.at(2);
    QTest::newRow("Sata") << "Apina" << numerot.at(3) << numerot.at(3);
}

void TestAgent::connectionTest()
{
    QFETCH(QString, Nimi);
    QFETCH(unsigned short, Konnektiot);
    QFETCH(unsigned short, Result);
    unsigned short nolla = 0;

    Agent* agentti = new Agent(Nimi, 0);
    QCOMPARE(agentti->connections(), nolla);
    agentti->setConnections(Konnektiot);
    QCOMPARE(agentti->connections(), Result);
    agentti->setConnections(0);
    QCOMPARE(agentti->connections(), nolla);
    agentti->modifyConnections(Konnektiot);
    QCOMPARE(agentti->connections(), Result);
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
        loka2_.push_back(lk);
    }
    QTest::addColumn<QString>("agentinnimi");
    QTest::addColumn<std::shared_ptr<Interface::Location >>("Lokaatio");

    QTest::newRow("Eka") << "Apina" << loka2_.at(0);
    QTest::newRow("Toka") << "Apina" << loka2_.at(1);
    QTest::newRow("Kolmas") << "Apina" << loka2_.at(2);
    QTest::newRow("Neljas") << "Apina" << loka2_.at(3);
    QTest::newRow("Viides") << "Apina" << loka2_.at(4);
    QTest::newRow("Kuudes") << "Apina" << loka2_.at(5);
    QTest::newRow("Seitsemäs") << "Apina" << loka2_.at(6);
    QTest::newRow("Kahdeksas") << "Apina" << loka2_.at(7);
}

void TestAgent::locationTest()
{
    QFETCH(QString, agentinnimi);
    QFETCH(std::shared_ptr<Interface::Location>, Lokaatio);

    Agent* agentti = new Agent(agentinnimi,false);
    //std::shared_ptr<Interface::Location> location = std::make_shared<Interface::Location>(*lokaatio);
    QVERIFY(agentti->location().expired()); // Eli location null
    QVERIFY(agentti->placement().expired());
    agentti->setPlacement(Lokaatio);
    QCOMPARE(agentti->placement().lock(), Lokaatio);
    delete agentti;
}

void TestAgent::ownerTest_data()
{
    std::vector<QString> nimet {"Erkki", "*€¨ä'ë", "Kermainen kulmakuuma kundiukko", "Hengenpelastajatyttö", "Metsä miäs", "", "Salmiakki_on_hyvää", "Suklaamyös"};
    for(unsigned int i = 0; i < 8; ++i){
        //Interface::Player* pelaaja = new Interface::Player(i, nimet.at(i));
        std::shared_ptr<Interface::Player> pelaaja = std::make_shared<Interface::Player>(peli_, i, nimet.at(i));
        //nimet_.push_back(location);
        nimet_.push_back(pelaaja);
    }
    QTest::addColumn<QString>("agentinnimi");
    QTest::addColumn<std::shared_ptr<Interface::Player >>("Pelaaja");

    QTest::newRow("Eka") << "Apina" << nimet_.at(0);
    QTest::newRow("Toka") << "Apina" << nimet_.at(1);
    QTest::newRow("Kolmas") << "Apina" << nimet_.at(2);
    QTest::newRow("Neljas") << "Apina" << nimet_.at(3);
    QTest::newRow("Viides") << "Apina" << nimet_.at(4);
    QTest::newRow("Kuudes") << "Apina" << nimet_.at(5);
    QTest::newRow("Seitsemäs") << "Apina" << nimet_.at(6);
    QTest::newRow("Kahdeksas") << "Apina" << nimet_.at(7);
}

void TestAgent::ownerTest()
{
    QFETCH(QString, agentinnimi);
    QFETCH(std::shared_ptr<Interface::Player>, Pelaaja);

    Agent* agentti = new Agent(agentinnimi,false);
    //std::shared_ptr<Interface::Location> location = std::make_shared<Interface::Location>(*lokaatio);
    QVERIFY(agentti->owner().expired()); // Eli owner null
    agentti->setOwner(Pelaaja);
    QVERIFY(!agentti->owner().expired());
    QCOMPARE(agentti->owner().lock(), Pelaaja);
    delete agentti;
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
