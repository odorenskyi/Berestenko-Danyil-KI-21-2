#include <iostream>
#include <cstring>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Modules-berestenko.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    fstream file;
    string inputWords[5] = {"життя веселих студентів","Літняя сесія","Arc Warden","теорія всесвітнього вибуху","академзаборгованість студента"};
    string expectedOutput[5] = {"життя веселих студентів","Літняя      ","ARC WARDEN","теорія всесвітнього вибуху","                     студента"};
    float s_calcx[5] = {7, 8, 16, 1, 9};
    float s_calcy[5] = {3, 2, 4, 5, 8};
    float s_calcz[5] = {5, 10, 7, 6, 11};
    string expres[5] = {"-31.383818", "-52.435154", "-2978.509521", "2.552058", "-82.564102"};
    int binnum[5] = {64,52,614,1632,88};
    string expbinnum[5] = {"00000000000000000000000001000000","00000000000000000000000000110100","00000000000000000000001001100110",
                            "00000000000000000000011001100000","00000000000000000000000001011000"};
    string file_name = "dOutput.txt";

    authorInfo("dOutput.txt");
    for(int i = 0; i < 5; i++){
        cout << boolalpha
             << "10 - Запис авторської інформації у вихідний файл: "
             << authorInfo("dOutput.txt") << endl;
        cout << boolalpha
             << "10 - Запис тексту до вхідного файлу: "
             << (inputWords[i].compare(inputFileTxt("dInput.txt", inputWords[i])) == 0) << endl;
        cout << boolalpha
             << "10.1 - дозапис тексту у вихідний файл: "
             << (expectedOutput[i].compare(language("dOutput.txt",inputWords[i])) == 0) << endl;
        cout << boolalpha
             << "10.2(2) - Дозапис часу редагування файлу до вхідного файлу: "
             << article_62("dInput.txt") << endl;
        cout << boolalpha
             << "10.3(1) - Результат виконання функції s_calculation до вихідного файлу: "
             <<(expres[i].compare(to_string(sCalculationInFile("dOutput.txt",s_calcx[i],s_calcy[i],s_calcz[i]))) == 0) << endl;
        cout << boolalpha
             << "10.3(2) - Результат виконання функції numberBinFile до вихідного файлу: "
             << (expbinnum[i].compare(numberBinFile("dOutput.txt",binnum[i]))== 0) << endl << endl;

        _getch();
    }
    cout << "Зробити очищення файлу Так - Y, Ні - N: " << endl;
     while(true){
             switch(getch()){
             case 'Y': file.open(file_name, ios_base::out);
                       file << "";
                       file.close(); break;
             case 'N': cout << "Закриття додатку" << endl; break;
             default: cout << "\a"; continue;
             }
             break;
         }
    return 0;
}
