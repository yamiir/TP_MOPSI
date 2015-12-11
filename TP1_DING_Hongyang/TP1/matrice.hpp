//
//  matrice.hpp
//  TP1
//
//  Created by dhy on 24/09/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#ifndef matrice_hpp
#define matrice_hpp
#include <iostream>
#include <stdio.h>

class Matrice{
    float* tab;
    int nlig, ncol;
    int * comp;
    public:
    Matrice ( int h, int w);
    ~Matrice();
    Matrice (const Matrice & A);
    int nlignes() const {
        return nlig;
    }
    int ncolones() const {
        return ncol;
    }
    float operator () (int i, int j) const;
    float& operator () (int i, int j) ;
    Matrice operator + (const Matrice& B) const;
    Matrice operator +=(Matrice B) ;

    Matrice operator * (const Matrice& B) const;
    Matrice& operator = (const Matrice& B);

};
std::ostream & operator << (std::ostream & str, const Matrice& A);
Matrice rand_matrice(Matrice A);
#endif /* matrice_hpp */
