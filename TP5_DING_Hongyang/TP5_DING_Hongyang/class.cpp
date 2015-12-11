//
//  class.cpp
//  TP5_DING_Hongyang
//
//  Created by dhy on 12/11/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include "class.hpp"
#include <vector>
using namespace std;

float Polynome:: operator()(float x)const{
    float s=0;
    for(int i=0; i<coeff.size();i++){
        s=coeff[i]*pow(x,i)+s;
    }
    return s;
}
Function* Polynome::derivee() const{
    vector<float> c(coeff.size()-1);
    for (int i=0;i<c.size();i++)
        c[i]=coeff[i+1]*(i*1);
    return new Polynome(c);
}
Function* Polynome::clone() const {
    return new Polynome(*this);
}

Function* Trigo::clone() const{
    return new Trigo(*this);
};

Function* Trigo::derivee() const{
    Trigo *D=new Trigo("  ");
    D->integrale=clone();
    return D;
};

float Function::inverse(float y) const{
    int i=0;
    float xm=1;
    float xn=0;
    Function * df=derivee();
    while (i<100 && abs(xm-xn)>=eps){
        xn=0;
        xn=xm+(y-this->operator()(xm))/ df->operator()(xm);// fuite de mémoire, chaque itération on redéfinir derivee()
        float temp;
        temp=xn;
        xn=xm;
        xm=temp;
        i++;
    }
    delete df;
    return xm;
}

