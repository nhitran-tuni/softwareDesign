#ifndef CARDCONTROLLER_HH
#define CARDCONTROLLER_HH

#include <QObject>
#include "cardmodel.hh"

class CardController : public QObject
{
    Q_OBJECT
public:
    explicit CardController(QObject *parent = nullptr, CardModel *card = nullptr);

    Q_INVOKABLE void generateCardValue();
    Q_INVOKABLE void setCardChoice(const QString &choice);
    Q_INVOKABLE void resetPoints();
signals:
private:
    CardModel *card;
};

#endif // CARDCONTROLLER_HH
