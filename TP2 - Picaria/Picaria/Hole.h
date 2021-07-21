#ifndef HOLE_H
#define HOLE_H

#include <QObject>
#include <QPushButton>

class Hole : public QPushButton {
    Q_OBJECT
    Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged)

public:
    enum State {
        EmptyState,
        RedState,
        BlueState,
        SelectableState
    };
    Q_ENUM(State)

    int id;

    explicit Hole(QWidget *parent = nullptr);
    virtual ~Hole();

    State state() const { return m_state; }
    void setState(State State);   
    Hole *N, *S, *E, *W, *NE, *NW, *SE, *SW;
    static void setCommonNeighbors(Hole* hole[]);
    static void setModeNeighbors(Hole* hole[], int holeCount);

public slots:
    void reset();

signals:
    void stateChanged(State State);

private:
    State m_state;

    static QPixmap stateToPixmap(State state);

private slots:
    void updateHoleIcon(State state);

};

#endif // HOLE_H
