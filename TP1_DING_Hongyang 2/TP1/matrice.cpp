//
//  matrice.cpp
//  TP1
//
//  Created by dhy on 24/09/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include "matrice.hpp"
#include <cassert>
#include <iostream>
using namespace std;
Matrice ::Matrice(int i, int j){
    nlig=i;
    ncol=j;
    tab= new float [nlig*ncol];
    comp=new int;
    *comp=1;
    cout<<"constructuer "<<" nlig="<<nlig<<"ncol="<<"ncol"<<endl;
                
}

Matrice :: Matrice(const Matrice & A){
    tab=A.tab;
    nlig=A.nlig;
    ncol=A.ncol;
    comp=A.comp;
    (*comp)++;
    cout<<"constructeur par copie"<<"nlig="<<nlig<<"ncol="<<ncol<<endl;
}
Matrice::~Matrice(){
    if(*comp==1){
        delete comp;
        delete []tab;
        cout<<" destructeur deleted"<<endl;

    }
    else
        (*comp)--;
    cout<<" destructeur comp--"<<endl;
}
float Matrice :: operator ()(int i,int j)const
{
    assert(i>=0 && i<=nlig && j>=0 && j<=ncol);
    return tab[(i)*ncol+j];
    }
float& Matrice::operator () (int i, int j) {
    
    assert(i>=0 && i<=nlig && j>=0 && j<=ncol);
    if(*comp==1)
        return tab[(i)*ncol+j];
    
    
    float *tab1=tab;
    tab=new float [ncol*nlig];
    for(int k=0; k<nlig; k++){
        for(int l=0; l<ncol;l++){
            tab[k*ncol+l]=tab1[k*ncol+l];
        }
    }
    
    
    return tab[(i)*ncol+j];
}
Matrice Matrice::operator + (const Matrice & B) const{
    assert(nlig==B.nlig&&ncol==B.ncol);
    Matrice A(nlig,ncol);
    for (int k=0;k<nlig; k++){
        for(int l=0;l<ncol ;l++){
            A(k,l)=tab[k*nlig+l]+B(k,l);
        }
    }
    return A;
}

Matrice Matrice::operator*(const Matrice& B)const{
    assert(ncol==B.nlignes());
    Matrice A(nlig,B.ncol);
    for (int k=0;k<nlig; k++){
        for(int l=0;l<B.ncol ;l++){
            for(int a=0;a<ncol;a++){
                A(k,l)+=tab[k*nlig+a]+B(a,l);
            }
        }
    }
    return A;
}

Matrice& Matrice:: operator = (const Matrice& B){
    if(*comp==1){
        if(nlig==B.nlig && ncol==B.ncol){
    for (int k=0;k<nlig;k++){
        for(int l=0;l<ncol;l++){
            this->tab[k*ncol+l]=B.tab[k*ncol+l];
        }
    }
    }
        else{
            delete [] tab;
            delete [] comp;
            nlig=B.nlig;
            ncol=B.ncol;
            tab=new float[nlig*ncol];
            comp=new int;
            *comp=1;
            for (int k=0;k<nlig;k++){
                for(int l=0;l<ncol;l++){
                    this->tab[k*ncol+l]=B.tab[k*ncol+l];
                }
            }

            
        }
    }
    else
    {
    ncol=B.ncol;
    nlig=B.nlig;
        tab=new float[ncol*nlig];
        (*comp)--;
        
        comp=new int;
        *comp=1;

    for (int k=0;k<nlig;k++){
        for(int l=0;l<ncol;l++){
            this->tab[k*ncol+l]=B.tab[k*ncol+l];
        }
    }
    }
    return *this;
}


Matrice Matrice::operator += (Matrice B){
    return *this=*this+B;
}

std::ostream & operator << (std::ostream & str, const Matrice& A){
    for (int k=0;k<A.nlignes();k++){
        for (int l=0; l<A.ncolones();l++){
            str<<A(k,l)<<' ';
        }
        str<<std::endl;}
    return str;
}
Matrice rand_matrice(Matrice A){
    for (int i=0;i<A.nlignes();i++){
        for(int j=0;j<A.ncolones();j++){
            A(i,j)=rand()%100;
        }
    }
    return A;
}








