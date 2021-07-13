#include "Picaria.h"
#include "ui_Picaria.h"

#include <QDebug>
#include <QMessageBox>
#include <QActionGroup>
#include <QSignalMapper>

Picaria::Player state2player(Hole::State state) {
    switch (state) {
    case Hole::RedState:
        return Picaria::RedPlayer;
    case Hole::BlueState:
        return Picaria::BluePlayer;
    default:
        Q_UNREACHABLE();
    }
}

Hole::State player2state(Picaria::Player player) {
    return player == Picaria::RedPlayer ? Hole::RedState : Hole::BlueState;
}

Picaria::Picaria(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Picaria),
      m_mode(Picaria::NineHoles),
      m_player(Picaria::RedPlayer),
      m_phase(Picaria::DropPhase) {

    ui->setupUi(this);

    QActionGroup* modeGroup = new QActionGroup(this);
    modeGroup->setExclusive(true);
    modeGroup->addAction(ui->action9holes);
    modeGroup->addAction(ui->action13holes);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(updateMode(QAction*)));
    QObject::connect(this, SIGNAL(modeChanged(Picaria::Mode)), this, SLOT(reset()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    QObject::connect(this, SIGNAL(gameOver(Picaria::Player)), this, SLOT(showGameOver()));

    QSignalMapper* map = new QSignalMapper(this);
    for (int id = 0; id < 13; ++id) {
        QString holeName = QString("hole%1").arg(id+1, 2, 10, QChar('0'));
        Hole* hole = this->findChild<Hole*>(holeName);
        Q_ASSERT(hole != nullptr);

        m_holes[id] = hole;
        map->setMapping(hole, id);
        QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
    }
#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(play(int)));
#else
    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));
#endif

    this->reset();

    this->adjustSize();
    this->setFixedSize(this->size());
}

Picaria::~Picaria() {
    delete ui;
}

void Picaria::setMode(Picaria::Mode mode) {
    if (m_mode != mode) {
        m_mode = mode;
        emit modeChanged(mode);
    }
}

void Picaria::switchPlayer() {
    m_player = m_player == Picaria::RedPlayer ?
                Picaria::BluePlayer : Picaria::RedPlayer;
    this->updateStatusBar();
}

void Picaria::play(int id) {
    Hole* hole = m_holes[id];

    qDebug() << "clicked on: " << hole->objectName();

    if(this->m_phase == DropPhase){
        this->drop(hole);
        this->updateStatusBar();
    } else if(this->m_phase == MovePhase) {
        this->move(hole);
        this->updateStatusBar();
    }

}

void Picaria::drop(Hole* hole) {
    if (hole->state() == Hole::EmptyState) {
        hole->setState(player2state(m_player));

        if (this->isGameOver()){
            emit gameOver(m_player);
        }else {
            holeDropCounter++;
            if (holeDropCounter == 6)
                m_phase = MovePhase;

            this->switchPlayer();
        }
    }
}

void Picaria::move(Hole* hole){
    if(hole->state() == player2state(m_player)){

    }
}

void Picaria::reset() {
    // Reset each hole.
    for (int id = 0; id < 13; ++id) {
        Hole* hole = m_holes[id];
        hole->reset();

        // Set the hole visibility according to the board mode.
        switch (id) {
        case 3:
        case 4:
        case 8:
        case 9:
            hole->setVisible(m_mode == Picaria::ThirteenHoles);
            break;
        default:
            break;
        }
    }

    // Reset the player and phase.
    this->holeDropCounter = 0;
    m_player = Picaria::RedPlayer;
    m_phase = Picaria::DropPhase;

    // Finally, update the status bar.
    this->updateStatusBar();
}

bool Picaria::isGameOver(){
    if(m_holes[0]->state() == player2state(m_player)){
        if(m_holes[1]->state() == player2state(m_player) && m_holes[2]->state() == player2state(m_player)){
            return true;
        } else if(m_holes[5]->state() == player2state(m_player) && m_holes[10]->state() == player2state(m_player)){
            return true;
        }
    }
    if(m_holes[12]->state() == player2state(m_player)){
        if(m_holes[7]->state() == player2state(m_player) && m_holes[2]->state() == player2state(m_player)){
            return true;
        } else if(m_holes[11]->state() == player2state(m_player) && m_holes[10]->state() == player2state(m_player)){
            return true;
        }
    }
    if(m_holes[6]->state() == player2state(m_player)){
        if(m_holes[5]->state() == player2state(m_player) && m_holes[7]->state() == player2state(m_player)){
            return true;
        } else if(m_holes[1]->state() == player2state(m_player) && m_holes[11]->state() == player2state(m_player)){
            return true;
        }
    }
    if(this->mode() == Picaria::NineHoles){
        if(m_holes[6]->state() == player2state(m_player)){
            if(m_holes[0]->state() == player2state(m_player) && m_holes[12]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[2]->state() == player2state(m_player) && m_holes[10]->state() == player2state(m_player)){
                return true;
            }
        }
    } else if(this->mode() == Picaria::ThirteenHoles){
        if(m_holes[6]->state() == player2state(m_player)){
            if(m_holes[3]->state() == player2state(m_player) && m_holes[9]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[4]->state() == player2state(m_player) && m_holes[8]->state() == player2state(m_player)){
                return true;
            }
        }
        if(m_holes[3]->state() == player2state(m_player)){
            if(m_holes[0]->state() == player2state(m_player) && m_holes[6]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[1]->state() == player2state(m_player) && m_holes[5]->state() == player2state(m_player)){
                return true;
            }
        }
        if(m_holes[4]->state() == player2state(m_player)){
            if(m_holes[1]->state() == player2state(m_player) && m_holes[7]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[2]->state() == player2state(m_player) && m_holes[6]->state() == player2state(m_player)){
                return true;
            }
        }
        if(m_holes[8]->state() == player2state(m_player)){
            if(m_holes[5]->state() == player2state(m_player) && m_holes[11]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[6]->state() == player2state(m_player) && m_holes[10]->state() == player2state(m_player)){
                return true;
            }
        }
        if(m_holes[9]->state() == player2state(m_player)){
            if(m_holes[6]->state() == player2state(m_player) && m_holes[12]->state() == player2state(m_player)){
                return true;
            } else if(m_holes[7]->state() == player2state(m_player) && m_holes[11]->state() == player2state(m_player)){
                return true;
            }
        }
    }
    return false;
}

void Picaria::showGameOver() {
    QString winner (m_player == Picaria::RedPlayer ? "vermelho" : "azul");
    QMessageBox::information(this, tr("Fim de jogo"), tr("Vitória do jogador %1").arg(winner));
    this->reset();
}

void Picaria::showAbout() {
    QMessageBox::information(this, tr("About"), tr("Picaria\n\nArthur Severo de Souza - svzr.47@gmail.com\nVictor Le Roy Matos - victorlrmatos@gmail.com"));
}

void Picaria::updateMode(QAction* action) {
    if (action == ui->action9holes)
        this->setMode(Picaria::NineHoles);
    else if (action == ui->action13holes)
        this->setMode(Picaria::ThirteenHoles);
    else
        Q_UNREACHABLE();
}

void Picaria::updateStatusBar() {
    QString player(m_player == Picaria::RedPlayer ? "vermelho" : "azul");
    QString phase(m_phase == Picaria::DropPhase ? "colocar" : "mover");

    ui->statusbar->showMessage(tr("Fase de %1: vez do jogador %2").arg(phase).arg(player));
}
