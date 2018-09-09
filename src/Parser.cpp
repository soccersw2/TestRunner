//
// Created by Eleven on 9/9/2018.
//

#include "../include/Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

Parser::Parser() {

}

vector<LabelDataFile> Parser::parseAllFiles(string filesPath) {

    vector<LabelDataFile> labelDataFileVector;

    for (int i = 100; i < 999; i++) {
        string fileNameWithPath = filesPath + "x_label" + to_string(i) + ".txt";
        if (fileExists(fileNameWithPath)) {
            cout << "\nFile Name: " << fileNameWithPath << endl;
            LabelDataFile labelDataFile = parseSingleFile(fileNameWithPath);
        } else {
            //cout << to_string(i) << " file does not exists" << endl;
        }
    }

    return labelDataFileVector;
}

LabelDataFile Parser::parseSingleFile(string fileName) {

    LabelDataFile *labelDataFile = new LabelDataFile;

    ifstream infile(fileName);
    int line = 1;

    while (infile) {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );
        vector <string> dataVector;

        while (ss) {
            if (line == 1) {
                break;
            }
            string s;
            if (!getline( ss, s, ',' )) break;
            dataVector.push_back( s );
        }

        if (line != 1) {
            LabelDataLine labelDataLine = recordData(dataVector);
            labelDataFile->addLabelDataLine(labelDataLine);
        }
        line++;
    }
    if (!infile.eof()) {
        cerr << "File stream error\n";
    }

    return *labelDataFile;
}

LabelDataLine Parser::recordData(vector<string> dataVector) {

    enum DataType {TIME, RX, LBL, HEX, TRANSLATION, VALUE, UNITS};

    LabelDataLine *labelDataLine = new LabelDataLine();

    for (int i = 0; i < dataVector.size(); i++) {
        switch(i) {
            case TIME:
                labelDataLine->setTime(stof(dataVector[i]));
                break;
            case RX:
                labelDataLine->setRx(stoi(dataVector[i]));
                break;
            case LBL:
                labelDataLine->setLbl((int)stol(dataVector[i], NULL, 8));
                break;
            case HEX:
                labelDataLine->setHex((int)stol(dataVector[i], NULL, 16));
                break;
            case TRANSLATION:
                labelDataLine->setTranslation(dataVector[i]);
                break;
            case VALUE:
                labelDataLine->setValue(stof(dataVector[i]));
                break;
            case UNITS:
                labelDataLine->setUnits(dataVector[i]);
                break;
            default:
                break;
        }
    }

    labelDataLine->computeMessage();
    labelDataLine->printValues();

    return *labelDataLine;
}

bool Parser::fileExists(const string fileName) {
    return ( access( fileName.c_str(), F_OK ) != -1 );
}
