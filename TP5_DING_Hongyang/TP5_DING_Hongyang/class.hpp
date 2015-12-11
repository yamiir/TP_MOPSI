//
//  class.hpp
//  TP5_DING_Hongyang
//
//  Created by dhy on 12/11/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#ifndef class_hpp
#define class_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <assert.h>
const float eps=1e-5f;
class Function{
protected:
    Function *integrale;
    
public:
    Function(){integrale=0;};
    
    virtual float operator()(float x)const{
        assert(integrale!=0);
        return ((*integrale)(x+eps)-(*integrale)(x))/eps;
    }
    virtual ~ Function(){
        delete integrale;
    };
    virtual Function* clone() const=0;
    virtual Function * derivee() const=0;
    virtual float inverse(float y) const;
};

class Polynome:public Function{
protected:

    std::vector<float> coeff;
    float a; float b;
    Polynome(float i, float j){
        coeff.push_back(a);
        coeff.push_back(b);
    }

public:
    Polynome(std::vector<float> c){
        coeff=c;
    }

    float operator()(float x) const;
    virtual Function * derivee() const;
    
    virtual Function * clone() const;
    //virtual float inverse(float y) const;
};
class affine:public Polynome{
public:
    affine(float i, float j):Polynome(i,j){
        a=i;b=j;
}


};

class Trigo: public Function{
    std::string nom;
public:
    Trigo(std::string type){
        nom=type;
    };
    Function* derivee() const;
    Function* clone() const;
    float operator()(float x)const{
        if(nom=="cos")
            return cos(x);
        if(nom=="sin")
            return sin(x);
        if(nom=="tan")
            return tan(x);
        return Function:: operator()(x);
    }
    //virtual float inverse(float y) const;
};


#endif /* class_hpp */
