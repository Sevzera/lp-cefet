#include "Hole.h"

Hole::Hole(QWidget *parent)
    : QPushButton(parent),
      m_state(Hole::EmptyState) {
    this->updateHoleIcon(m_state);

    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateHoleIcon(State)));
}

Hole::~Hole() {
}

void Hole::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

void Hole::reset() {
    m_state = Hole::EmptyState;
    this->updateHoleIcon(m_state);
}

void Hole::setCommonNeighbors(Hole* hole[]){

    hole[0]->N = nullptr;
    hole[0]->S = hole[5];
    hole[0]->E = hole[1];
    hole[0]->W = nullptr;
    hole[1]->N = nullptr;
    hole[1]->S = hole[6];
    hole[1]->E = hole[2];
    hole[1]->W = hole[0];
    hole[2]->N = nullptr;
    hole[2]->S = hole[7];
    hole[2]->E = nullptr;
    hole[2]->W = hole[1];

    hole[3]->N = nullptr;
    hole[3]->S = nullptr;
    hole[3]->E = nullptr;
    hole[3]->W = nullptr;
    hole[4]->N = nullptr;
    hole[4]->S = nullptr;
    hole[4]->E = nullptr;
    hole[4]->W = nullptr;

    hole[5]->N = hole[0];
    hole[5]->S = hole[10];
    hole[5]->E = hole[6];
    hole[5]->W = nullptr;
    hole[6]->N = hole[1];
    hole[6]->S = hole[11];
    hole[6]->E = hole[7];
    hole[6]->W = hole[5];
    hole[7]->N = hole[2];
    hole[7]->S = hole[12];
    hole[7]->E = nullptr;
    hole[7]->W = hole[6];

    hole[8]->N = nullptr;
    hole[8]->S = nullptr;
    hole[8]->E = nullptr;
    hole[8]->W = nullptr;
    hole[9]->N = nullptr;
    hole[9]->S = nullptr;
    hole[9]->E = nullptr;
    hole[9]->W = nullptr;

    hole[10]->N = hole[5];
    hole[10]->S = nullptr;
    hole[10]->E = hole[11];
    hole[10]->W = nullptr;
    hole[11]->N = hole[6];
    hole[11]->S = nullptr;
    hole[11]->E = hole[12];
    hole[11]->W = hole[10];
    hole[12]->N = hole[7];
    hole[12]->S = nullptr;
    hole[12]->E = nullptr;
    hole[12]->W = hole[11];

}

void Hole::setModeNeighbors(Hole* hole[], int holeCount){

    for(int id = 0; id < 13; ++id){
        if(holeCount == 9){
            switch (id)
            {
            case 0:
                hole[0]->NE = nullptr;
                hole[0]->NW = nullptr;
                hole[0]->SE = hole[6];
                hole[0]->SW = nullptr;
                break;
            case 1:
                hole[1]->NE = nullptr;
                hole[1]->NW = nullptr;
                hole[1]->SE = hole[7];
                hole[1]->SW = hole[5];
                break;
            case 2:
                hole[2]->NE = nullptr;
                hole[2]->NW = nullptr;
                hole[2]->SE = nullptr;
                hole[2]->SW = hole[6];
                break;
            case 3:
                hole[3]->NE = nullptr;
                hole[3]->NW = nullptr;
                hole[3]->SE = nullptr;
                hole[3]->SW = nullptr;
                break;
            case 4:
                hole[4]->NE = nullptr;
                hole[4]->NW = nullptr;
                hole[4]->SE = nullptr;
                hole[4]->SW = nullptr;
                break;
            case 5:
                hole[5]->NE = hole[1];
                hole[5]->NW = nullptr;
                hole[5]->SE = hole[11];
                hole[5]->SW = nullptr;
                break;
            case 6:
                hole[6]->NE = hole[2];
                hole[6]->NW = hole[0];
                hole[6]->SE = hole[12];
                hole[6]->SW = hole[10];
                break;
            case 7:
                hole[7]->NE = nullptr;
                hole[7]->NW = hole[1];
                hole[7]->SE = nullptr;
                hole[7]->SW = hole[11];
                break;
            case 8:
                hole[8]->NE = nullptr;
                hole[8]->NW = nullptr;
                hole[8]->SE = nullptr;
                hole[8]->SW = nullptr;
                break;
            case 9:
                hole[9]->NE = nullptr;
                hole[9]->NW = nullptr;
                hole[9]->SE = nullptr;
                hole[9]->SW = nullptr;
                break;
            case 10:
                hole[10]->NE = hole[6];
                hole[10]->NW = nullptr;
                hole[10]->SE = nullptr;
                hole[10]->SW = nullptr;
                break;
            case 11:
                hole[11]->NE = hole[7];
                hole[11]->NW = hole[5];
                hole[11]->SE = nullptr;
                hole[11]->SW = nullptr;
                break;
            case 12:
                hole[12]->NE = nullptr;
                hole[12]->NW = hole[6];
                hole[12]->SE = nullptr;
                hole[12]->SW = nullptr;
                break;

            default:
                break;
            }
        } else {
            switch(id){
            case 0:
                hole[0]->NE = nullptr;
                hole[0]->NW = nullptr;
                hole[0]->SE = hole[3];
                hole[0]->SW = nullptr;
                break;
            case 1:
                hole[1]->NE = nullptr;
                hole[1]->NW = nullptr;
                hole[1]->SE = hole[4];
                hole[1]->SW = hole[3];
                break;
            case 2:
                hole[2]->NE = nullptr;
                hole[2]->NW = nullptr;
                hole[2]->SE = nullptr;
                hole[2]->SW = hole[4];
                break;
            case 3:
                hole[3]->NE = hole[1];
                hole[3]->NW = hole[0];
                hole[3]->SE = hole[6];
                hole[3]->SW = hole[5];
                break;
            case 4:
                hole[4]->NE = hole[2];
                hole[4]->NW = hole[1];
                hole[4]->SE = hole[7];
                hole[4]->SW = hole[6];
                break;
            case 5:
                hole[5]->NE = hole[3];
                hole[5]->NW = nullptr;
                hole[5]->SE = hole[8];
                hole[5]->SW = nullptr;
                break;
            case 6:
                hole[6]->NE = hole[4];
                hole[6]->NW = hole[3];
                hole[6]->SE = hole[9];
                hole[6]->SW = hole[8];
                break;
            case 7:
                hole[7]->NE = nullptr;
                hole[7]->NW = hole[4];
                hole[7]->SE = nullptr;
                hole[7]->SW = hole[9];
                break;
            case 8:
                hole[8]->NE = hole[6];
                hole[8]->NW = hole[5];
                hole[8]->SE = hole[11];
                hole[8]->SW = hole[10];
                break;
            case 9:
                hole[9]->NE = hole[7];
                hole[9]->NW = hole[6];
                hole[9]->SE = hole[12];
                hole[9]->SW = hole[11];
                break;
            case 10:
                hole[10]->NE = hole[8];
                hole[10]->NW = nullptr;
                hole[10]->SE = nullptr;
                hole[10]->SW = nullptr;
                break;
            case 11:
                hole[11]->NE = hole[9];
                hole[11]->NW = hole[8];
                hole[11]->SE = nullptr;
                hole[11]->SW = nullptr;
                break;
            case 12:
                hole[12]->NE = nullptr;
                hole[12]->NW = hole[9];
                hole[12]->SE = nullptr;
                hole[12]->SW = nullptr;
                break;

            default:
                break;
            }
        }
    }
}

QPixmap Hole::stateToPixmap(State state) {
    switch (state) {
    case Hole::EmptyState:
        return QPixmap(":empty");
    case Hole::RedState:
        return QPixmap(":red");
    case Hole::BlueState:
        return QPixmap(":blue");
    case Hole::SelectableState:
        return QPixmap(":selectable");
    default:
        return QPixmap();
    }
}

void Hole::updateHoleIcon(State state) {
    this->setIcon(Hole::stateToPixmap(state));
}
