#ifndef SCENA_H
#define SCENA_H

#include <QGraphicsScene>

class Scena : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scena(QObject *parent = nullptr);

signals:

};

#endif // SCENA_H
