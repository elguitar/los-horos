#ifndef PELIKORTTI_H
#define PELIKORTTI_H

#include <QWidget>
#include "game.h"
#include "cardinterface.h"
using std::make_shared;
using std::shared_ptr;

namespace Ui {
class Pelikortti;
}

class Pelikortti : public QWidget
{
    Q_OBJECT

public:
    explicit Pelikortti(QWidget *parent = 0);
    explicit Pelikortti(shared_ptr<Interface::CardInterface> kortti, QWidget *parent = 0);
    ~Pelikortti();

private:
    Ui::Pelikortti *ui;
    shared_ptr<Interface::CardInterface> kortti_;
    QString tyyppi_;
};

#endif // PELIKORTTI_H
