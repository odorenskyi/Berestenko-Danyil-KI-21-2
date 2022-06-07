#include <iostream>
#include <fstream>

#include "struct_type_project_5.h"
#include "Modules_Berestenko.h"
#include "Modules_Nazarevskiy.h"
#include "Modules_Lisevich.h"


using namespace std;


int main()
{
    system("chcp 1251 & cls");
    vector<data> database;
    string filename;
    filename = "database.dat";
    loadDatabase(database,filename);
    do {
        cout << "Виберіть дію яку хочете виконати: "<<endl;
        cout << "1 - виведення довідника у консоль" << endl
             << "2 - додати інформацію у довідник" << endl
             << "3 - пошук інформації у довіднику" << endl
             << "4 - видалення інформації у довіднику" << endl
             << "5 - збереження інформації у довіднику та закриття програми" << endl
             << "Введіть ключ дії: ";
        int option = 0;
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore();
        }
        string city;
        int code = 0;
        switch (option) {
            case 1:
                print_database(database);
                break;
            case 2:
                append_data(database);
                break;
            case 3:
                cout << "Введіть назву міста інформацію якого ви хочете знайти: " << endl << ">>> ";
                cin >> city;
                search_data(database, city);
                break;
            case 4:
                cout << "Введіть назву міста інформацію про яке ви хочете вилучити: " << endl << ">>> ";
                while (!(cin >> city)) {
                    cin.clear();
                    cin.ignore();
                }
                remove_data(database, city);
                break;
            case 5:
                saveDatabase(database,filename);
                return 0;
            default:
                continue;
        }
        system("pause");
        system("cls");
    } while(true);
}
