//
//  Tree.hpp
//  TP3_intTree
//
//  Created by dhy on 17/10/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp
#include <vector>
#include <stdio.h>
#include <stdexcept>
using namespace std;
#include<iostream>
template <typename T>

class Tree {
    // Node information
    T data;
    // Sequence of sons (empty if none)
    std::vector <Tree*> sons;
public:
    // Create a node with given information
    Tree (T d);
    ~Tree();
    // Return information of this node
    T getData();
    // Set information of this node
    void setData(T d);
    // Return the number of sons of this node
    int nbSons();
    // Return the son at position pos, if any (considering left-most son is at position 0)
    Tree* getSon(int pos);
    // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void setSon(int pos, Tree* newSon);
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(Tree* newSon);
    // Remove right-most son of this node
    void removeLastSon();
    void display(std::string prefix, std::string indent);
    void addSon(int pos, Tree<T>* son);
    void removeSon(int pos);
};
#endif /* Tree_hpp */
template <typename T>


Tree<T>:: Tree(T d){
    data=d;
}
template <typename T>

Tree<T>:: ~Tree(){
    for(T i=0;i<sons.size();i++){
        delete sons[i];
    }
}
template <typename T>

T Tree<T>:: getData(){
    return data;
}
// Set information of this node
template <typename T>

void Tree<T>::setData(T d){
    data=d;
}
// Return the number of sons of this node
template <typename T>

int Tree<T>:: nbSons(){
    return int(sons.size());
}
template <typename T>

// Return the son at position pos, if any (considering left-most son is at position 0)
Tree <T>* Tree<T>:: getSon(int pos){
    if (pos < 0 || pos >= sons.size())
        throw out_of_range("index error when calling getSon(int)");
    return sons[pos];
}
// Replace the exisiting son at position pos with newSon (left-most son at position 0)
template <typename T>

void Tree<T>:: setSon(int pos, Tree<T>* newSon){
    if (pos < 0 || pos >= sons.size())
        throw out_of_range("index error when calling setSons(int)");
    delete sons[pos];
    sons[pos]=newSon;
}
// Add newSon as supplementary right-most son of this node
template <typename T>

void Tree<T>:: addAsLastSon(Tree<T>* newSon){
    
    sons.push_back(newSon);
}
// Remove right-most son of this node
template <typename T>

void Tree<T>:: removeLastSon(){
    if (sons.size() == 0)
        throw out_of_range("cant remove son from a non son node");
    delete sons[nbSons()-1];
    sons.pop_back();
}
template <typename T>

void Tree<T>:: display(string prefix, string indent){
    cout <<prefix<<indent<<data<<endl;
    indent=indent+"  ";
    for(int i=0;i<sons.size();i++){
        sons[i]->display(prefix, indent);
    }
    
}
template <typename T>
void Tree<T>::addSon(int pos, Tree<T>* son){
    auto it= sons.begin();
    if(sons.size() >=pos){
        it=sons.insert(it+pos, son);
    }
}

template <typename T>
void Tree<T>::removeSon(int pos)
{   if( sons.size()>pos){
    sons.erase(sons.begin()+pos);
}
    else
        cerr <<"try to remove a son doesn't exist"<<endl;
}


