#ifndef AKKUNA_H
#define AKKUNA_H

#include <QWidget>

namespace Ui {
class Akkuna;
}

class Akkuna : public QWidget
{
    Q_OBJECT

public:
    explicit Akkuna(QWidget *parent = 0);
    ~Akkuna();

private:
    Ui::Akkuna *ui;
};

#endif // AKKUNA_H
