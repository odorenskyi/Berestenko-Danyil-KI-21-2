#ifndef MODULES-BERESTENKO_H_INCLUDED
#define MODULES-BERESTENKO_H_INCLUDED

struct population_flow{
    int population;
    int flow;
};

float s_calculation(float x, float y,float z);

population_flow changes(int population,int death,int birth,int emigraation,int imigration);

short int bal_boforta(float wind[24]);

short int binary_func(unsigned int num);

#endif // MODULES-BERESTENKO_H_INCLUDED
