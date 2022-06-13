#include "AditionFunc.h"


using namespace std;

int main()
{
    string tsDirPath = "./";
    string testResPath = "TestResults.txt";


    system("chcp 1251 & cls");
    string path = __FILE__;
    if (path.find("lab12\\prj\\") == -1) {
        for (int i = 0; i < 100; i++) {
            cout << "\a";
        }
        ofstream testRes(testResPath);
        if (testRes.is_open()) {
            testRes << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            testRes.close();
        }
        else {
            cout << "Помилка при роботі з файлом " << testResPath << "." << endl;
        }
        return -1;
    }

    ifstream mainFile("main.cpp");
    if (mainFile.is_open()) {
        tsDirPath = "../../Testsuite/";
        mainFile.close();
    }
    else {
        tsDirPath = "../Testsuite/";
    }

    testResPath = tsDirPath+testResPath;
    ofstream testRes(testResPath, ios::out);
    if (testRes.is_open()) testRes.close();

    string TSPath = tsDirPath+"TS.txt";


    ifstream caseFile(TSPath);
    if(!caseFile.is_open()){
        cout << TSPath << " is not opened!";
        return -1;
    }
    ofstream resultFile(testResPath);
    if(!resultFile.is_open()){
        cout << testResPath << " is not opened!";
        return -1;
    }


    ClassLab12_Berestenko piramid;


    for (int i = 1; i < 14; i++) {
        string piramidHeight;
        string piramidLength;
        string piramidVolume;
        string bufLine;

        getline(caseFile, bufLine);
        piramidHeight = bufLine.erase(0, 15);

        getline(caseFile, bufLine);
        piramidLength = bufLine.erase(0, 15);

        getline(caseFile, bufLine);
        piramidVolume = bufLine.erase(0, 15);

        piramid.setPiramidHeight(stof(piramidHeight));
        piramid.setPiramidLength(stof(piramidLength));
        bufLine = to_string(getPiramidVolume(piramid.getPiramidHeight(),piramid.getPiramidLength()));

        declareTestSuiteResults(resultFile,piramid,bufLine,piramidVolume,i);
    }

    caseFile.close();
    resultFile.close();
    system("pause");
    return 0;
}
