//
//  main.cpp
//  TP3_IntTree
//
//  Created by dhy on 08/10/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Tree.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    
    Tree<double>* root = new Tree<double>(12.5);
    root->addAsLastSon(new Tree<double>(8.0));
    root->getSon(0)->addAsLastSon(new Tree<double>(4));
    root->getSon(0)->addAsLastSon(new Tree<double>(9.5));
    
    root->addAsLastSon(new Tree<double>(23));
    root->getSon(1)->addAsLastSon(new Tree<double>(17));
    root->getSon(1)->getSon(0)->addAsLastSon(new Tree<double>(15));
    //root->getSon(0)->getSon(0)->removeLastSon();
    string prefix="*";
    string indent=" ";
    root->addSon(0,new Tree<double> (6));
    root->removeSon(0);

    try{
        Tree<int>* root2=new Tree<int>(1);
        root2->getSon(5);
    }catch(std::out_of_range){
        cout<<"Exception1 caught "<<endl;
    }
    
    try{
        Tree<int>* root3=new Tree<int>(12);
        
        root3->setSon(10,root3);
    }catch(std::out_of_range){
        cout<<"Exception2 caught "<<endl;
    }
    
    try{
        Tree<int>* root4=new Tree<int>(17);
        root4->removeLastSon();
    }catch(std::out_of_range){
        cout<<"Exception3 caught "<<endl;
    }
    root->display(prefix,indent);
    delete root;
    return 0;
}
