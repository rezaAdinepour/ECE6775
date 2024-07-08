#include <iostream>
#include <math.h>


using namespace std;
#define ITERATION 7



float* _pow(int itr)
{
    static float pow_inv_i[ITERATION];
    for(int i = 0; i < itr; i++)
    {
        pow_inv_i[i] = pow(2, -i);
    }

    return pow_inv_i;
}


float* rotation_angle(int itr)
{
    static float rot_angl[ITERATION];
    float* p;

    p = _pow(itr);

    for(int i = 0; i < itr; i++)
    {
        rot_angl[i] = atan(p[i]) * (180 / M_PI);
    }

    return rot_angl;
}


float* scaling_factor(int itr)
{
    static float prod[ITERATION - 1];

    for(int i = 0; i < itr; i++)
    {
        prod[i] = sqrt(1 + pow(2, -2 * i));
    }
    return prod;
}


float* cordic_cos_calc(float phi, int itr)
{
    float phi_calc = 0;
    float* ptr = &phi_calc;
    float* angle = rotation_angle(itr);
    int i = 0;

    while(abs(phi - *ptr) > 0.5)
    {
        if(*ptr < phi)
        {
            *ptr += angle[i];
            i++;
        }
        else
        {
            *ptr -= angle[i];
            i++;
        }
    }
    return ptr;
}







int main()
{
    float* result;

    result = cordic_cos_calc(90, ITERATION);

    cout << *result << endl;
    

    return 0;
}