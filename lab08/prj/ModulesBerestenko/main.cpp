
#include <cmath>

const double pi = 3.14159;
const double e = 2.71828;

float s_calculation(float x, float y,float z){
    return 0.5*((pow(y,2)+ 2*z)/sqrt(7*pi + x)) - sqrt(pow(e,abs(x))+ (sqrt(abs(y-z)))/sin(z*y));
}

