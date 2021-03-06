#include <cmath>
#include <fstream>
#include <ctime>
#include <cstring>
#include <bitset>
#include <string>


using namespace std;

const double pi = 3.14159;
const double e = 2.71828;

float s_calculation(float x, float y, float z){
    return 0.5*((pow(y,2)+ 2*z)/sqrt(7*pi + x)) - sqrt(pow(e,abs(x))+ (sqrt(abs(y-z)))/sin(z*y));
}

string inputFileTxt(string inputFilename, string sentence){
    ofstream inputFile(inputFilename);
    inputFile << sentence << endl << endl;
    inputFile.close();
    return sentence;
}

bool authorInfo(string outputFileName)
{
    ofstream outputFile(outputFileName);
	outputFile << "====================================================================" << endl
               << " Виконавець:         Берестенко Даниїл Олексійович" << endl
               << " Рік розробки:       2022" << endl
               << " Місто/Країна:       Кропивницький/Україна" << endl
               << " ВНЗ:                Центральний Національний Технічний Університет" << endl
               << "====================================================================" << endl << endl;
    outputFile.close();
}

string language(string outputFileName, string text)
{
    bool isEnglish = false;
    string w_search = text;
    ofstream outputFile(outputFileName, ios::app);
    if(outputFile.is_open() == false) {
        return text;
    }

    for(int i = 0; i < text.length(); i++){
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
            isEnglish = true;
            break;
        }
        else if((text[i] >= 'А' && text[i] <= 'Я') || (text[i] >= 'а' && text[i] <= 'я')){
            isEnglish = false;
            break;
        }
    }

    outputFile << "Мова: " << ((isEnglish == true) ? "Англійська\n" : "Україньска\n");

    if(isEnglish == true){
        for(int i =0; i < text.length(); i++){
            if(text[i] >= 'a' && text[i] <= 'z')
                w_search[i] = text[i] - 32;
            else
                w_search[i] = text[i];
        }
    }
    else {
        for(int i = 0; i < text.length(); i++){
            if((text[i] == 'л') && (text[i+1] == 'і') && (text[i+2] == 'н') &&
               (text[i+3] == 'о') && (text[i+4] == 'щ') && (text[i+5] == 'і'))
            {
                for(int j = 0; j < 6; j++)
                    w_search[i+j] = ' ';
            }
            if((text[i] == 'с') && (text[i+1] == 'е') && (text[i+2] == 'с') &&
               (text[i+3] == 'і') && (text[i+4] == 'я'))
            {
                for(int j = 0; j < 5; j++)
                    w_search[i+j] = ' ';
            }
            if((text[i] == 'а') && (text[i+1] == 'к') && (text[i+2] == 'а') && (text[i+3] == 'д') &&
               (text[i+4] == 'е') && (text[i+5] == 'м') && (text[i+6] == 'з') && (text[i+7] == 'а') &&
               (text[i+8] == 'б') && (text[i+9] == 'о') && (text[i+10] == 'р') && (text[i+11] == 'г') &&
               (text[i+12] == 'о') && (text[i+13] == 'в') && (text[i+14] == 'а') && (text[i+15] == 'н') &&
               (text[i+16] == 'і') && (text[i+17] == 'с') && (text[i+18] == 'т') && (text[i+19] == 'ь'))
            {
                for(int j = 0; j < 20; j++)
                    w_search[i+j] = ' ';
            }
        }
    }

    outputFile << w_search << endl;
    outputFile.close();
    return w_search;
}

bool article_62(string inputFileText){
    string article_62;
    ofstream inputfile(inputFileText,ios::app);
    if(inputfile.is_open()){
        article_62 = "\nСтаття 62,права осіб, які навчаються у закладах вищої освіти\n"
                  "1. Особи, які навчаються у вищих навчальних закладах, мають право на:\n"
                  "1) вибір форми навчання під час вступу до вищого навчального закладу;\n"
                  "2) безпечні і нешкідливі умови навчання, праці та побуту;\n"
                  "3) трудову діяльність у позанавчальний час;\n"
                  "4) додаткову оплачувану відпустку у зв’язку з навчанням за основним місцем роботи, скорочений робочий час та інші пільги, передбачені законодавством для осіб, які поєднують роботу з навчанням;\n"
                  "5) безоплатне користування бібліотеками, інформаційними фондами, навчальною, науковою та спортивною базами вищого навчального закладу;\n"
                  "6) безоплатне забезпечення інформацією для навчання у доступних форматах з використанням технологій, що враховують обмеження життєдіяльності, зумовлені станом здоров’я (для осіб з особливими освітніми потребами);\n"
                  "7) користування виробничою, культурно-освітньою, побутовою, оздоровчою базами вищого навчального закладу у порядку, передбаченому статутом вищого навчального закладу;\n"
                  "8) забезпечення гуртожитком на строк навчання у порядку, встановленому законодавством;\n"
                  "9) участь у науково-дослідних, дослідно-конструкторських роботах, конференціях, симпозіумах, виставках, конкурсах, представлення своїх робіт для публікації;\n"
                  "10) участь у заходах з освітньої, наукової, науково-дослідної, спортивної, мистецької, громадської діяльності, що проводяться в Україні та за кордоном, у встановленому законодавством порядку;\n"
                  "11) участь в обговоренні та вирішенні питань удосконалення навчального процесу, науково-дослідної роботи, призначення стипендій, організації дозвілля, побуту, оздоровлення;\n"
                  "12) внесення пропозицій щодо умов і розміру плати за навчання;\n"
                  "13) участь у громадських об’єднаннях;\n"
                  "14) участь у діяльності органів громадського самоврядування вищого навчального закладу, інститутів, факультетів, відділень, вченої ради вищого навчального закладу, органів студентського самоврядування;\n"
                  "15) вибір навчальних дисциплін у межах, передбачених відповідною освітньою програмою та робочим навчальним планом, в обсязі, що становить не менш як 25 відсотків загальної кількості кредитів ЄКТС, передбачених для даного рівня вищої освіти. При цьому здобувачі певного рівня вищої освіти мають право вибирати навчальні дисципліни, що пропонуються для інших рівнів вищої освіти, за погодженням з керівником відповідного факультету чи підрозділу;\n"
                  "16) навчання одночасно за декількома освітніми програмами, а також у декількох вищих навчальних закладах, за умови отримання тільки однієї вищої освіти за кожним ступенем за кошти державного (місцевого) бюджету;\n"
                  "17) академічну мобільність, у тому числі міжнародну;\n"
                  "18) отримання соціальної допомоги у випадках, встановлених законодавством;\n"
                  "19) зарахування до страхового стажу відповідно до Закону України \"Про загальнообов’язкове державне пенсійне страхування\" періодів навчання на денній формі навчання у вищих навчальних закладах, аспірантурі, докторантурі, клінічній ординатурі, інтернатурі, резидентурі, за умови добровільної сплати страхових внесків;\n"
                  "20) академічну відпустку або перерву в навчанні із збереженням окремих прав здобувача вищої освіти, а також на поновлення навчання у порядку, встановленому центральним органом виконавчої влади у сфері освіти і науки;\n"
                  "21) участь у формуванні індивідуального навчального плану;\n"
                  "22) моральне та/або матеріальне заохочення за успіхи у навчанні, науково-дослідній і громадській роботі, за мистецькі та спортивні досягнення тощо;\n"
                  "23) захист від будь-яких форм експлуатації, фізичного та психічного насильства;\n"
                  "24) безоплатне проходження практики на підприємствах, в установах, закладах та організаціях, а також на оплату праці під час виконання виробничих функцій згідно із законодавством;\n"
                  "25) канікулярну відпустку тривалістю не менш як вісім календарних тижнів на навчальний рік;\n"
                  "26) отримання цільових пільгових державних кредитів для здобуття вищої освіти у порядку, визначеному Кабінетом Міністрів України;\n"
                  "27) оскарження дій органів управління вищого навчального закладу та їх посадових осіб, педагогічних і науково-педагогічних працівників;\n"
                  "28) спеціальний навчально-реабілітаційний супровід та вільний доступ до інфраструктури вищого навчального закладу відповідно до медико-соціальних показань за наявності обмежень життєдіяльності, зумовлених станом здоров’я.\n"
                  "2. Особи, які навчаються у вищих навчальних закладах за денною формою навчання за рахунок коштів державного або місцевих бюджетів, мають право на отримання стипендій у встановленому законодавством порядку.\n"
                  "3. Особи, які навчаються у вищих навчальних закладах за денною формою навчання, можуть отримувати інші стипендії, призначені фізичними (юридичними) особами.\n"
                  "4. Розмір стипендіального фонду вищого навчального закладу повинен забезпечувати виплату академічних стипендій не менш як двом третинам і не більш як 75 відсоткам студентів (курсантів невійськових вищих навчальних закладів) денної форми навчання, які навчаються за кошти державного бюджету, без урахування осіб, які отримують соціальні стипендії.\n"
                  "5. Розмір академічної та соціальної стипендій, порядок їх призначення і виплати встановлюються Кабінетом Міністрів України.\n"
                  "6. Розмір мінімальної академічної та соціальної стипендій для здобувачів освітніх ступенів вищої освіти не може бути меншим, ніж розмір прожиткового мінімуму з розрахунку на одну особу на місяць. Розмір мінімальної академічної та соціальної стипендій для здобувачів ступеня молодшого бакалавра не може бути меншим, ніж дві третини розміру прожиткового мінімуму з розрахунку на одну особу на місяць.\n"
                  "7. Академічні стипендії виплачуються не менш як двом третинам студентів (курсантів) кожного курсу (крім першого семестру першого року навчання) за кожною спеціальністю, без урахування осіб, які отримують соціальні стипендії. Академічну стипендію отримують студенти (курсанти), які згідно з рейтингом, складеним у вищому навчальному закладі за результатами семестрового контролю, здобули найкращі результати навчання. "
                     "До проведення першого семестрового контролю академічна стипендія у мінімальному розмірі призначається всім студентам (курсантам), зарахованим до вищого навчального закладу на перший курс навчання.\n"
                  "8. Особам, які досягли значних успіхів у навчанні та/або науковій діяльності, за рішенням вченої ради вищого навчального закладу можуть призначатися персональні стипендії.\n"
                  "9. Здобувачі вищої освіти, які навчаються у вищих навчальних закладах за денною формою навчання, мають право на пільговий проїзд у транспорті у порядку, встановленому Кабінетом Міністрів України.\n"
                  "10. Студенти, курсанти вищих навчальних закладів мають право на отримання студентського квитка, зразок якого затверджується центральним органом виконавчої влади у сфері освіти і науки.\n";
        inputfile << article_62 << endl;
        time_t t;
        t = time(NULL);
        inputfile << ctime(&t);
        inputfile.close();
        return true;
    }
    return false;
}

float sCalculationInFile(string outputFileName, float x, float y, float z)
{
    ofstream outputFile(outputFileName,ios::app);
    outputFile << "Результат виконання функції s_calculation: " << s_calculation(x,y,z) << endl;
    outputFile.close();
    return s_calculation(x,y,z);
}

string numberBinFile(string outputFileName, int b)
{
    ofstream outputFile(outputFileName, ios::app);
    bitset<32> b_number(b);
    outputFile << "Число " << b << " у двійковому коді: " << b_number << endl;
    outputFile.close();
    return b_number.to_string();
}
