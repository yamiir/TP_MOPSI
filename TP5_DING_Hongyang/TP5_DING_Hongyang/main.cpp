//
//  main.cpp
//  TP5_DING_Hongyang
//
//  Created by dhy on 12/11/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include <iostream>
#include "class.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    float v[]={0,0,0,1};
    vector<float> f(begin(v),end(v));

    Polynome fx(f);
    Trigo TAN("tan");
    float PI=4*TAN.inverse(1);
    affine gx(2,3);
    cout<<"27^(1/3)="<<fx.inverse(27)<<endl;
    cout<<"4*tan(1)="<<PI<<endl;
    cout<< gx.inverse(10)<<endl;
    return 0;
}
