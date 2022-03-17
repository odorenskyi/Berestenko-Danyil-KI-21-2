#include <iostream>
#include <cmath>
#include "ModulesBerestenko.h""

using namespace std;

void test_s_calculation()
{
    system("chcp 1251 && cls");

    float possibleresult[7] = {-0.1996,3.1953,20.5652, -18.9801,
                                6.8943, 13.2827, -6.7869};

    float x[7] = {1, 2, -3, -6, 0.1, -0.4, 4};
    float y[7] = {3, 8, 16, -2, 11, 12, 0.8};
    float z[7] = {3, 1, 4, 2, -0.3, 6.4, 3.2};

    for (short int i = 0; i < 7; i++)
    {
        cout << round(s_calculation(x[i], y[i], z[i])*10000)/10000.0 << " = " << possibleresult[i] << endl;
        if (round(s_calculation(x[i], y[i], z[i])*10000)/10000.0 == round(possibleresult[i]*10000)/10000.0)
        {
            cout << "Test #[" << i + 1 << "]: PASSED\n";
        }
        else
        {
            cout << "Test #[" << i + 1 << "]: FAILED\n";
        }
    }
}

int main()
{
    test_s_calculation();
}
