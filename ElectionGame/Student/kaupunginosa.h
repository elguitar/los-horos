#ifndef KAUPUNGINOSA_H
#define KAUPUNGINOSA_H

#include <QWidget>

namespace Ui {
class Kaupunginosa;
}

class Kaupunginosa : public QWidget
{
    Q_OBJECT

public:
    explicit Kaupunginosa(QWidget *parent = 0);
    ~Kaupunginosa();

private:
    Ui::Kaupunginosa *ui;
};

#endif // KAUPUNGINOSA_H
