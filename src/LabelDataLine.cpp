//
// Created by Eleven on 9/9/2018.
//

#include "../include/LabelDataLine.h"
#include <string>
#include <iostream>

using namespace std;

LabelDataLine::LabelDataLine(float time, int rx, int lbl, int hex,
                     string translation, float value, string units) {
    this->time = time;
    this->rx = rx;
    this->lbl = lbl;
    this->hex = hex;
    this->translation = translation;
    this->value = value;
    this->units = units;
    this->message = computeMessage();
}

void LabelDataLine::printValues() {
    cout << "Time: "        << to_string(this->time) << ", ";
    cout << "Rx: "          << to_string(this->rx) << ", ";
    cout << "Label: "       << to_string(this->lbl) << ", ";
    cout << "Hex: "         << to_string(this->hex) << ", ";
    cout << "Translation: " << this->translation << ", ";
    cout << "Value "        << to_string(this->value) << ", ";
    cout << "Units: "       << this->units << ", ";
    cout << "\nComputed Message: " << this->message << endl;
    cout << endl;
}

float LabelDataLine::getTime() {
    return this->time;
}

long int LabelDataLine::getMessage() {
    return this->message;
}

LabelDataLine::LabelDataLine() {
    this->time = 0;
    this->rx = 0;
    this->lbl = 0;
    this->hex = 0;
    this->translation = "";
    this->value = 0;
    this->units = "";
    this->message = 0;
}

void LabelDataLine::setTime(float time) {
    this->time = time;
}

void LabelDataLine::setRx(int rx) {
    this->rx = rx;
}

void LabelDataLine::setLbl(int lbl) {
    this->lbl = lbl;
}

void LabelDataLine::setHex(long int hex) {
    this->hex = hex;
}

void LabelDataLine::setTranslation(string translation) {
    this->translation = translation;
}

void LabelDataLine::setValue(float value) {
    this->value = value;
}

void LabelDataLine::setUnits(string units) {
    this->units = units;
}

long int LabelDataLine::computeMessage() {
    long int message = this->hex;
    message = message << 8;
    message = message | this->lbl;
    if (parityEven(message)){
        cout << "Parity Even" << endl;
        message = message | 2147483648; //0x80000000 bit mask;
    } else cout << "Parity Odd" << endl;

    //cout << "Computed Message: " << dec << message << endl;
    this->message = message;
    return this->message;
}

bool LabelDataLine::parityEven(int message) {
    return !(message & 1);
}
