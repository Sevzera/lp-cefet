#ifndef PICARIA_H
#define PICARIA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Picaria; }
QT_END_NAMESPACE

class Picaria : public QMainWindow {
    Q_OBJECT

public:
    Picaria(QWidget *parent = nullptr);
    ~Picaria();

private:
    Ui::Picaria *ui;
};
#endif // PICARIA_H
