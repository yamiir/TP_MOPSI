//
//  intTree.cpp
//  TP3_intTree
//
//  Created by dhy on 08/10/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include "intTree.hpp"
#include <vector>
using namespace std;
#include<iostream>

IntTree::IntTree(int d){
    data=d;
    
}
IntTree:: ~IntTree(){
    for(int i=0;i<sons.size();i++){
        delete sons[i];
    }
}
int IntTree:: getData(){
    return data;
}
// Set information of this node
void IntTree::setData(int d){
    data=d;
}
// Return the number of sons of this node
int IntTree:: nbSons(){
    return int(sons.size());
}
// Return the son at position pos, if any (considering left-most son is at position 0)
IntTree* IntTree:: getSon(int pos){
    if (pos>=sons.size()){
        cerr <<" tring to get a son doesn't exist"<<endl;
        exit(1);
    }
    
    return sons[pos];
}
// Replace the exisiting son at position pos with newSon (left-most son at position 0)
void IntTree:: setSon(int pos, IntTree* newSon){
    if (pos>=sons.size()){
        cerr <<" tring to set a son doesn't exist"<<endl;
        exit(2);
    }
    sons[pos]=newSon;
}
// Add newSon as supplementary right-most son of this node
void IntTree:: addAsLastSon(IntTree* newSon){
    
    sons.push_back(newSon);
}
// Remove right-most son of this node
void IntTree:: removeLastSon(){
    if(sons.size()<=0){
        cerr <<" tring to remove a son from a empty vector"<<endl;
        exit(3);
    }
    sons.pop_back();
}
void IntTree:: display(string prefix, string indent){
    cout <<prefix<<indent<<data<<endl;
    indent=indent+"  ";
    for(int i=0;i<sons.size();i++){
        sons[i]->display(prefix, indent);
    }
}




