//
//  intTree.hpp
//  TP3_intTree
//
//  Created by dhy on 08/10/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#ifndef intTree_hpp
#define intTree_hpp


#include <vector>
using namespace std;
class IntTree {
    // Node information
    int data;
    // Sequence of sons (empty if none)
    std::vector <IntTree*> sons;
public:
    // Create a node with given information
    IntTree(int d);
    ~IntTree();
    // Return information of this node
    int getData();
    // Set information of this node
    void setData(int d);
    // Return the number of sons of this node
    int nbSons();
    // Return the son at position pos, if any (considering left-most son is at position 0)
    IntTree* getSon(int pos);
    // Replace the exisiting son at position pos with newSon (left-most son at position 0)
    void setSon(int pos, IntTree* newSon);
    // Add newSon as supplementary right-most son of this node
    void addAsLastSon(IntTree* newSon);
    // Remove right-most son of this node
    void removeLastSon();
    void display(string prefix, string indent);
};
#endif /* intTree_hpp */
