//
// Created by Eleven on 9/9/2018.
//

#ifndef TESTRUNNER_LABELDATALINE_H
#define TESTRUNNER_LABELDATALINE_H

#include <string>
#include <windef.h>

using namespace std;

class LabelDataLine {
private:
    float time;
    int rx;
    int lbl;
    int hex;
    string translation;
    float value;
    string units;
    int message;

public:
    LabelDataLine(float time, int rx, int lbl, int hex,
              string translation, float value, string units);
    LabelDataLine();

    void setTime(float time);
    void setRx(int rx);
    void setLbl(int lbl);
    void setHex(long int hex);
    void setTranslation(string translation);
    void setValue(float value);
    void setUnits(string units);
    int computeMessage();
    bool parityEven(int message);

    void printValues();
    float getTime();
    int getMessage();
};


#endif //TESTRUNNER_LABELDATALINE_H
