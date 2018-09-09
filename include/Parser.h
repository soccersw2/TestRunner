//
// Created by Eleven on 9/9/2018.
//

#ifndef TESTRUNNER_PARSER_H
#define TESTRUNNER_PARSER_H

#include <string>
#include "LabelDataFile.h"

using namespace std;

class Parser {
private:

public:
    Parser();
    vector<LabelDataFile> parseAllFiles(string filesPath);
    LabelDataFile parseSingleFile(string fileName);
    LabelDataLine recordData(vector<string> data);

    void checkValues();

    bool fileExists(string fileName);
};


#endif //TESTRUNNER_PARSER_H
