#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <chrono>
#include "../include/LabelDataLine.h"
#include "../include/LabelDataFile.h"
#include "../include/Parser.h"

using namespace std;

//string const FILES_PATH = "D:\\School_Fall_2018\\Senior Design\\SN0074_081418\\0a118c\\";
//string const FILES_PATH = "C:\\Users\\Eleven\\CLionProjects\\untitled1\\";

//string const FILES_PATH = "C:\\Users\\Jonathan\\CLionProjects\\TestRunner\\SN0074_081418\\0a118c\\";
string const FILES_PATH = "C:\\Users\\Jonathan\\CLionProjects\\TestRunner\\testFiles\\";
string const FILE_PATH= "C:\\Users\\Eleven\\CLionProjects\\untitled1\\x_label203_test.txt";

vector<LabelDataFile> labelDataFileVector;

void sendMessages() {

    using namespace std::chrono;

    cout << "Opening socket and sending messages";

    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    duration<double> timeSpan;

    while (1) {
        timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - startTime);
        //cout << "Time: " << timeSpan.count() << endl;

        for (LabelDataFile labelDataFile : labelDataFileVector) {
            for (LabelDataLine labelDataLine : labelDataFile.getDataFromFile()) {
                timeSpan = duration_cast<duration<double>>(high_resolution_clock::now() - startTime);
                cout << "Time: " << timeSpan.count() << endl;
                if (labelDataLine.getTime() <= timeSpan.count()) {
                    cout << "Sending message: " + labelDataLine.getMessage() << endl;
                    labelDataFile.removeLabelDataLine(labelDataLine);
                }
            }
        }
        if (timeSpan.count() > 60) break;
    }
}

int main() {

    Parser *parser = new Parser();

    //cout << bitset<32>(dataFromFile.front().getMessage()) << endl;
    cout << "Parsing files...";
    labelDataFileVector = parser->parseAllFiles(FILES_PATH);
    sendMessages();
    return 0;
}

