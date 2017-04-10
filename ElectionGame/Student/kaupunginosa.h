#ifndef KAUPUNGINOSA_H
#define KAUPUNGINOSA_H

#include <QWidget>
#include "location.h"
#include "game.h"
#include "pelikortti.h"
#include "deckinterface.h"
#include <QDebug>
#include <QPixmap>

namespace Ui {
class Kaupunginosa;
}

class Kaupunginosa : public QWidget
{
    Q_OBJECT

public:
    explicit Kaupunginosa(QWidget *parent = 0);
    explicit Kaupunginosa(std::shared_ptr<Interface::Location> location, QWidget *parent=0);
    ~Kaupunginosa();

public slots:
    void nostaKortti();
    void nostaAgentti();
    void asetaAgentti();
    void asetaPelimerkki();

    void asetaPakkakuvat();
private:
    Ui::Kaupunginosa *ui;
    std::shared_ptr<Interface::Location> location_;
};

#endif // KAUPUNGINOSA_H
