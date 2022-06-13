#ifndef MODULES_BERESTENKO_H_INCLUDED
#define MODULES_BERESTENKO_H_INCLUDED

#include <cmath>

class ClassLab12_Berestenko{
public:
    ClassLab12_Berestenko(){}
    ClassLab12_Berestenko(double height, double side_length);

    void setPiramidHeight(double height);
    double getPiramidHeight();
    void setPiramidLength(double side_length);
    double getPiramidLength();


private:
    double height = 1.0;
    double side_length = 4.0;
};

ClassLab12_Berestenko::ClassLab12_Berestenko(double height, double side_length){
    this->height = height;
    this->side_length = side_length;
}

void ClassLab12_Berestenko::setPiramidHeight(double height){
    this->height = height;
}

void ClassLab12_Berestenko::setPiramidLength(double side_length){
    this->side_length = side_length;
}

double ClassLab12_Berestenko::getPiramidHeight(){
    return height;
}

double ClassLab12_Berestenko::getPiramidLength(){
    return side_length;
}


double getPiramidVolume(double height,double side_length){
    return ((((side_length * side_length * sqrt(3))/4) * height)/3);
}
#endif // MODULES_BERESTENKO_H_INCLUDED
