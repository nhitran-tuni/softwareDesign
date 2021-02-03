#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include<QString>
#include<QRandomGenerator>
#include<vector>
#include<algorithm>

const std::vector<QString> CARD = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
const std::vector<QString> BIG = {"9","10","J","Q","K","A"};

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cardValue READ cardValueGet WRITE setCardValue NOTIFY cardValueChanged)
//    Q_PROPERTY(int right READ right WRITE setRight NOTIFY rightChanged)
//    Q_PROPERTY(int wrong READ wrong WRITE setWrong NOTIFY wrongChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);
    void setCardValue(QString val);
//    void setRight(int rightValue);
//    void setWrong(int wrongValue);

    Q_INVOKABLE QString cardValueGet();
//    int right() const;
//    int wrong() const;

    Q_INVOKABLE bool compare(bool isSmall);

signals:
    void cardValueChanged();
//    void rightChanged();
//    void wrongChanged();

private:
    QString cardValue_;
//    int right_;
//    int wrong_;
};

#endif // BACKEND_H
