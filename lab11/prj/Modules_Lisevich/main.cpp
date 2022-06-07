#include <iostream>
#include <fstream>
#include <vector>
#include "struct_type_project_5.h"

using namespace std;

void remove_data(vector<data> &database,string city){
    auto iter = database.cbegin();
    for(int i = 0; i < database.size(); i++){
        if(database[i].city == city){
            database.erase(iter + i);

            cout << "Запис видалено" << endl;

            return;
        }
    }
    cout << "Запис не знайдено" << endl;
}


void append_data(vector<data> &database){
    data phone_code;
    cout << "Введіть назву міста: ";
    cin >> phone_code.city;
    cout << "Введіть телефоний код міста: ";
    cin >> phone_code.code;
    database.push_back(phone_code);
}
