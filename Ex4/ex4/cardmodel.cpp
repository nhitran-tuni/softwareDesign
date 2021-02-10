#include "cardmodel.hh"

#include <algorithm>

//// use the preprocessor directives to support older versions of Qt with the random number generation
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    #include <QRandomGenerator>
#else
    #include <QDateTime>
#endif

const std::vector<QString> CardModel::SMALL_CARDS = {"2", "3", "4", "5", "6", "7"};
const std::vector<QString> CardModel::BIG_CARDS = {"9", "10", "J", "Q", "K", "A"};
const std::vector<QString> CardModel::CARDS = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const size_t CardModel::POSSIBLE_CARD_VALUE_COUNT = CARDS.size();

CardModel::CardModel(QObject *parent) :
    QObject(parent),
    cardValue_{CARDS[0]},
    correctChoice_(false),
    correctAnswers_(0),
    incorrectAnswers_(0)
{
    // for Qt version 5.9 or earlier, setup the seed for the random number generator using the current time
    #if (QT_VERSION < QT_VERSION_CHECK(5, 10, 0))
        uint currentTime = QDateTime::currentDateTime().toTime_t();
        qsrand(currentTime);
    #endif
}

QString CardModel::getCardValue() const
{
    return cardValue_;
}

void CardModel::setCardValue()
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
        unsigned long index = QRandomGenerator::global()->bounded(static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #else
        unsigned long index = static_cast<unsigned long>(qrand() % static_cast<int>(POSSIBLE_CARD_VALUE_COUNT));
    #endif
    cardValue_ = CARDS.at(index);

    emit cardValueChanged();
}

void CardModel::setChoice(const QString &choice)
{
    PlayerChoice playerChoice = getPlayerChoice(choice);

    if (playerChoice == PlayerChoice::SMALL || playerChoice == PlayerChoice::BIG)
    {
        CardModel::CardSize cardSize = getCardSize();
        if ((cardSize == CardModel::CardSize::SMALL && playerChoice == PlayerChoice::SMALL) ||
            (cardSize == CardModel::CardSize::BIG && playerChoice == PlayerChoice::BIG))
        {
            correctChoice_ = true;
            ++correctAnswers_;
            emit correctAnswersChanged();
        }
        else
        {
            correctChoice_ = false;
            ++incorrectAnswers_;
            emit incorrectAnswersChanged();
        }
        emit choiceChanged();
    }
}

void CardModel::reset()
{
    correctAnswers_ = 0;
    emit correctAnswersChanged();

    incorrectAnswers_ = 0;
    emit incorrectAnswersChanged();
}

CardModel::CardSize CardModel::getCardSize() const
{
    if (std::find(BIG_CARDS.begin(), BIG_CARDS.end(), cardValue_) != BIG_CARDS.end())
    {
        return CardSize::BIG;
    }
    else if (std::find(SMALL_CARDS.begin(), SMALL_CARDS.end(), cardValue_) != SMALL_CARDS.end())
    {
        return CardSize::SMALL;
    }
    else
    {
        return CardSize::UNDEFINED;
    }
}

int CardModel::getCorrectAnswers() const
{
    return correctAnswers_;
}

int CardModel::getIncorrectAnswers() const
{
    return incorrectAnswers_;
}

bool CardModel::isCorrect() const
{
    return correctChoice_;
}

CardModel::PlayerChoice CardModel::getPlayerChoice(const QString &playerChoice)
{
    QString playerChoiceUpper = playerChoice.toUpper();
    if (playerChoiceUpper == "SMALL")
    {
        return PlayerChoice::SMALL;
    }
    else if (playerChoiceUpper == "BIG")
    {
        return PlayerChoice::BIG;
    }
    else
    {
        return PlayerChoice::UNKNOWN;
    }
}
