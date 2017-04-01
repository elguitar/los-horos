#ifndef AKKUNA_H
#define AKKUNA_H

#include <QWidget>
#include "player.h"
using std::make_shared;
using std::shared_ptr;

namespace Ui {
class Akkuna;
}

class Akkuna : public QWidget
{
    Q_OBJECT

public:
    explicit Akkuna(QWidget *parent = 0);
    void addPlayer(shared_ptr<Interface::Player> pelaaja);
    ~Akkuna();

private:
    Ui::Akkuna *ui;
};

#endif // AKKUNA_H
