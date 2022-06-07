#include <iostream>
#include <fstream>
#include <vector>
#include "struct_type_project_5.h"

using namespace std;

void loadDatabase(vector<data> &database, string filename){
    ofstream bout(filename, ios::app);
    bout.close();
    ifstream bin (filename, ios::in | ios::binary);
    int len;
    if (bin.is_open()){
        int fileLen = int(bin.seekg(0, ios::end).tellg());
        bin.seekg(0, ios::beg);
        while (bin.tellg() < fileLen) {

            data* tmpData = new data;
            len = 0;
            bin.read((char*)&len, sizeof(int));
            tmpData->city.resize(len);
            bin.read(&tmpData->city[0], len);
            bin.read((char*)&tmpData->code, sizeof(int));
            database.push_back(*tmpData);
            delete tmpData;
        }
        bin.close();
    }
    else
        cout << "Input not open" << endl;
}



void saveDatabase(vector<data> &database, string filename) {
    ofstream bout (filename, ios::out | ios::binary);
    if (bout.is_open()) {
        for (int i = 0, len; i < database.size(); i++){
            len = database[i].city.length();
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].city[0], len);
            bout.write((char*)&database[i].code, sizeof(int));
        }
        bout.close();
    }
    else {
        cerr << "\nНеможливо завантажити файл '" << filename << "'.";
        exit(1);
    }
}
