#ifndef CARDMODEL_HH
#define CARDMODEL_HH

#include <vector>
#include <QObject>

class CardModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ getCardValue NOTIFY cardValueChanged)
    Q_PROPERTY(int correctAnswers READ getCorrectAnswers NOTIFY correctAnswersChanged)
    Q_PROPERTY(int incorrectAnswers READ getIncorrectAnswers NOTIFY incorrectAnswersChanged)
    Q_PROPERTY(bool correct READ isCorrect NOTIFY choiceChanged)

public:
    enum class CardSize {
        SMALL,
        BIG,
        UNDEFINED
    };

    enum class PlayerChoice {
        SMALL,
        BIG,
        UNKNOWN
    };

    explicit CardModel(QObject *parent = nullptr);

    QString getCardValue() const;

    void setCardValue();
    void setChoice(const QString &choice);
    void reset();

    CardSize getCardSize() const;

    int getCorrectAnswers() const;
    int getIncorrectAnswers() const;
    bool isCorrect() const;

signals:
    void cardValueChanged();
    void correctAnswersChanged();
    void incorrectAnswersChanged();
    void choiceChanged();

private:
    QString cardValue_;
    bool correctChoice_;
    int correctAnswers_;
    int incorrectAnswers_;

    static const size_t POSSIBLE_CARD_VALUE_COUNT;
    static const std::vector<QString> SMALL_CARDS;
    static const std::vector<QString> BIG_CARDS;
    static const std::vector<QString> CARDS;

    PlayerChoice getPlayerChoice(const QString &playerChoice);
};

#endif // CARDMODEL_HH
