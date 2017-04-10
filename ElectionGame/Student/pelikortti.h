#ifndef PELIKORTTI_H
#define PELIKORTTI_H

#include <QWidget>

namespace Ui {
class Pelikortti;
}

class Pelikortti : public QWidget
{
    Q_OBJECT

public:
    explicit Pelikortti(QWidget *parent = 0);
    ~Pelikortti();

private:
    Ui::Pelikortti *ui;
};

#endif // PELIKORTTI_H
