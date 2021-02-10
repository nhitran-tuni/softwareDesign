#include "cardcontroller.hh"

CardController::CardController(QObject *parent, CardModel *card) :
    QObject(parent)
{
    this->card = card;
}

void CardController::generateCardValue()
{
    card->setCardValue();
}

void CardController::setCardChoice(const QString &choice)
{
    card->setChoice(choice);
}

void CardController::resetPoints()
{
    card->reset();
}

