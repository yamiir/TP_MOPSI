//
//  main.cpp
//  TP4
//
//  Created by dhy on 05/11/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class eleve{
public:
    string nom;
    int note;
    eleve(string s, int n){
        nom=s;
        note=n;
    }
    
    
};
class CompareNom{
public:
    int *ptr;
    bool operator()(eleve e1, eleve e2){
        (*ptr)++;
        if(e1.nom<e2.nom)
            return true;
        else
            return false;
    }
};
class CompareNote{
public:
    int *ptr;
    bool operator()(eleve e1, eleve e2){
        (*ptr)++;
        if(e1.note<e2.note)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<eleve> E;
    string Name[5]={"a","b","c","d","e"};
    int Note[5]={2,5,10,1,10};
    for (int i=0;i<5;i++){
        E.push_back(eleve(Name[i],Note[i]));
    }
    int compteur1=0;
    int compteur2=0;
    CompareNom cmn1;
    cmn1.ptr=&compteur1;
    CompareNote cmn2;
    cmn2.ptr=&compteur2;
    sort(E.begin(),E.end(),cmn2);
    for(vector<eleve>::iterator it=E.begin(); it!=E.end();it++){
        cout <<"nom: "<<it->nom<<" "<<"note:"<<it->note<<endl;
    }
    cout <<*cmn2.ptr<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
