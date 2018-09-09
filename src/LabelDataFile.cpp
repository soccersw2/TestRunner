//
// Created by Eleven on 9/9/2018.
//

#include <iostream>
#include "../include/LabelDataFile.h"

LabelDataFile::LabelDataFile() {
}

vector<LabelDataLine> LabelDataFile::getDataFromFile() {
    return this->dataFromFile;
}

void LabelDataFile::addLabelDataLine(LabelDataLine dataLine) {
    this->dataFromFile.push_back(dataLine);
}

bool LabelDataFile::isEmpty() {
    return dataFromFile.empty();
}

void LabelDataFile::removeLabelDataLine(LabelDataLine labelDataLine) {
    for (int i = 0; i < this->dataFromFile.size(); i++) {
        LabelDataLine data = this->dataFromFile[i];
        if (data.getMessage() == labelDataLine.getMessage()) {
            this->dataFromFile.erase(this->dataFromFile.begin() + i, this->dataFromFile.begin() + i);
            std::cout << "Erasing message: " + data.getMessage() << std::endl;
            break;
        }
    }
}
