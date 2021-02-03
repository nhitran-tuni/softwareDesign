#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{

}

void BackEnd::setCardValue(QString val) {
    if (cardValue_ == val) {
        return;
    }
    cardValue_ = val;
    emit cardValueChanged();
}

QString BackEnd::cardValueGet() {
    QString val = CARD[QRandomGenerator::global()->bounded(0,12)];
    this->setCardValue(val);
    return cardValue_;
}

//int BackEnd::right() const {return right_;}

//int BackEnd::wrong() const {return wrong_;}

//void BackEnd::setRight(int rightValue) {
//    if (right_ != rightValue) {
//        right_ = rightValue;
//    }
//    emit rightChanged();
//}

//void BackEnd::setWrong(int wrongValue) {
//    if (wrong_ != wrongValue) {
//        wrong_ = wrongValue;
//    }
//    emit wrongChanged();
//}

bool BackEnd::compare(bool isSmall) {
    if (cardValue_ == "8"){
        return true;
    }
    if (isSmall && std::find(BIG.begin(), BIG.end(), cardValue_) == BIG.end()) {
        return true;
    }
    if (!isSmall && std::find(BIG.begin(), BIG.end(), cardValue_) != BIG.end()) {
        return true;
    }
    return false;
}
