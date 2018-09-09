//
// Created by Eleven on 9/9/2018.
//

#ifndef TESTRUNNER_LABELDATAFILE_H
#define TESTRUNNER_LABELDATAFILE_H

#include <vector>
#include "LabelDataLine.h"

class LabelDataFile {
private:
    vector<LabelDataLine> dataFromFile;
public:
    LabelDataFile();
    vector<LabelDataLine> getDataFromFile();
    void addLabelDataLine(LabelDataLine dataLine);
    bool isEmpty();
    void removeLabelDataLine(LabelDataLine labelDataLine);
};


#endif //TESTRUNNER_LABELDATAFILE_H
