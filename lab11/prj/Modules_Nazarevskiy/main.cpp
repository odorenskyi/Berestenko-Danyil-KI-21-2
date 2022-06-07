#include <vector>
#include <iostream>
#include <fstream>
#include "struct_type_project_5.h"

using namespace std;

void search_data(vector<data> &database,string city){
    for(int i = 0; i < database.size(); i++){
        if(database[i].city == city){
            cout << "Місто - " << city << endl;
            cout << "Код - " << database[i].code << endl;
        }
    }
}


void print_database(vector<data> database){
    for(int i = 0; i < database.size(); i++){
        cout << "Місто - " << database[i].city << endl;
        cout << "Код - " << database[i].code << endl;
    }
}
