#ifndef KAUPUNGINOSA_H
#define KAUPUNGINOSA_H

#include <QWidget>
#include "location.h"

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

private:
    Ui::Kaupunginosa *ui;
    std::shared_ptr<Interface::Location> location_;
};

#endif // KAUPUNGINOSA_H
