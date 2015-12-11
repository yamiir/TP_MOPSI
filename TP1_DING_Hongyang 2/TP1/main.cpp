//
//  main.cpp
//  TP1
//
//  Created by dhy on 24/09/15.
//  Copyright © 2015 dhy. All rights reserved.
//
#include "matrice.hpp"
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    Matrice A(2,3);
    A=rand_matrice(A);
    Matrice B(3,2);
    B=rand_matrice(B);
    A+=A;
    A=A;
    int a=A(0,1);
    A(0,0)=5;
    Matrice D(4,4);
    D=A;
    Matrice E(2,2);
    E=A;
    Matrice F=B*A;
  
    cout<<B<<endl;
    cout<<D<<endl;
    cout<<E<<endl;
    cout<<D.ncolones()<<endl<<F<<endl;
    return 0;
}


