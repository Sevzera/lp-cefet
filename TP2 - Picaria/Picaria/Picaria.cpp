#include "Picaria.h"
#include "ui_Picaria.h"
#include <QDebug>

Picaria::Picaria(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Picaria) {
    ui->setupUi(this);

    this->adjustSize();
    this->setFixedSize(this->size());

    qDebug() << "row: " << ui->hole00->row();
    qDebug() << "col: " << ui->hole00->col();

}

Picaria::~Picaria() {
    delete ui;
}

