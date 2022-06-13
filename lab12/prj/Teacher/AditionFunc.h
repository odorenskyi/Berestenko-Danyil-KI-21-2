#ifndef ADITIONFUNC_H_INCLUDED
#define ADITIONFUNC_H_INCLUDED

#include "Modules_Berestenko.h"

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

bool fileInDirectory()
{
    string cpp = __FILE__;
    size_t found = cpp.find("\\lab12\\prj");

    if (found == string::npos) {
        ofstream resFile("../TestSuite/TestResults.txt");
        resFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        for (int i = 0; i < 100; i++) {
            cout << "\a";
        }
        resFile.close();
        return false;
    }
    return true;
}

bool filesIsOpen(ofstream &wfile, ifstream &rfile)
{
    if (!rfile.is_open() || !wfile.is_open() || !rfile || !wfile) {
        ofstream resFile("../TestSuite/TestResults.txt");
        resFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        resFile.close();
        return false;
    }
    return true;
}

void declareTestSuiteResults(ofstream &resFile, ClassLab12_Berestenko pir, string outArea, string expArea, int index)
{
    resFile << "----------------------------------------------------" << endl;
    resFile << "| TEST CASE " << setw(2) << index << setw(38) << "|" << endl;
    resFile << "| (input)    Piramid height: " << setw(17) << pir.getPiramidHeight() << " м   |" << endl;
    resFile << "| (input)    Piramid side length: " << setw(12) << pir.getPiramidLength() << " м   |" << endl;
    resFile << "| (output)   Piramid volume: " << setw(17) << outArea << " м^2 |" << endl;
    resFile << "| (expected) Piramid volume: " << setw(17) << expArea << " м^2 |" << endl;
    resFile << "| TEST CASE RESULT:       " << setw(20) << boolalpha << (expArea.compare(outArea) == 0) << "     |" << endl;
    resFile << "----------------------------------------------------" << endl;
}

#endif // ADITIONFUNC_H_INCLUDED
