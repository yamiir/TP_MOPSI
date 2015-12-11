//
//  main.cpp
//  TP2_DING_Hongyang
//
//  Created by dhy on 01/10/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#include <iostream>
#include <string>
#include<vector>
using namespace std;

string s1="3jbhvgh45";
string s2="46qsdzefwxcc";
//string s1="abcd";
//string s2="cadb";
vector<vector<int> > DDL;    //2D vector of distance Damerau levenshtein
vector<vector<int> > DL;     //  2D vector of distance levenstein
vector<vector<int> > I_L;   //  n vector for save modifications of string for levenstein.
int utd;

//     distance damerau levenstein

int distance_DL(int i, int j){              //distance damerau levenstein
    if(i<0||j<0)
        return abs(i-j);                    // initial distance
    if(DDL[i][j]!=-1)
        return DDL[i][j];
    else if (s1[i]==s2[j]){
        DDL[i][j]=min(min(distance_DL(i,j-1)+1,distance_DL(i-1,j)+1),distance_DL(i-1,j-1));// if the last lettres of each string are the same, we compare d(i,j-1)+1, d(i-1,j)+1 and d(i-1,j-1)
        
    return DDL[i][j];
    }
    
    else if (s1[i]==s2[j-1] && s1[i-1]==s2[j]){                 // if the last two lettres of string can be permuted
        DDL[i][j]=min(min(distance_DL(i,j-1)+1,distance_DL(i-1,j)+1),min(distance_DL(i-1,j-1)+1,distance_DL(i-2,j-2)+1));
        return DDL[i][j];
    }

    else{
        DDL[i][j]= min(min(distance_DL(i,j-1)+1,distance_DL(i-1,j)+1),distance_DL(i-1,j-1)+1);
        return DDL[i][j];
    }
}


//      distance lenvenshtein
int distance_L(int i, int j){       //distance levenshtein
    if(i<0||j<0)
        return abs(i-j);            // initial distance
    if(DL[i][j]!=-1)
        return DL[i][j];            //if DL[i][j]is already calculated.
    else if (s1[i]==s2[j]){


        if((distance_L(i, j-1)+1)<=(distance_L(i-1, j)+1)&&(distance_L(i, j-1)+1)<=(distance_L(i-1, j-1))){
            I_L[i][j]=2;                                                                            // insert s2[j] after s1[i]
            DL[i][j]=distance_L(i, j-1)+1;
        }
        else if((distance_L(i-1, j)+1)<=(distance_L(i, j-1)+1) && (distance_L(i-1, j)+1)<=(distance_L(i-1, j-1))){
            I_L[i][j]=0; //delete s1[i]
            DL[i][j]=distance_L(i-1, j)+1;
        }
        else if((distance_L(i-1, j-1))<=(distance_L(i-1,j)+1) && distance_L(i-1, j-1)<=(distance_L(i, j-1)+1)){
            I_L[i][j]=1;// dont need to change
            DL[i][j]=distance_L(i-1, j-1);
        }

        return DL[i][j];
    }
    

    
    else {
        //DL[i][j]= min(min(distance_L(i,j-1)+1,distance_L(i-1,j)+1),distance_L(i-1,j-1)+1);
        if((distance_L(i, j-1)+1)<=(distance_L(i-1, j)+1) && (distance_L(i, j-1)+1)<=(distance_L(i-1, j-1)+1)){
            I_L[i][j]=2;                                               //insert s2[j] after s1[i]
            DL[i][j]=distance_L(i, j-1)+1;
        }
        else if((distance_L(i-1, j)+1)<=(distance_L(i, j-1)+1) && (distance_L(i-1, j)+1)<=(distance_L(i-1, j-1)+1)){
            I_L[i][j]=0;                                            //delete s1[i]

            DL[i][j]=distance_L(i-1, j)+1;
        }
        else if((distance_L(i-1, j-1)+1)<=(distance_L(i-1, j)+1) && (distance_L(i-1, j-1)+1)<=(distance_L(i, j-1)+1)){
            I_L[i][j]=3;                                            // replace s1[i] with s2[j]
            DL[i][j]=distance_L(i-1, j-1)+1;
        }


        return DL[i][j];
    }
}

//      print modifications
void print_L(int i,int j){
    
    if(i<0&&j>=0){
        cout <<s1<<endl;
        for ( int k=0; k<abs(i-j);k++){
            s1.insert(0,s2,abs(i-j)-k,1);
        }
        return;
    }
    if(i<0&&j<0){
        cout<<s1<<endl;
        return;
    }
    if(i>=0&&j<0){
        cout <<s1<<endl;
        for (int k=0;k<abs(i-j);k++){
            s1.erase(0,1);
        }
        return;
    }

    if (I_L[i][j]==1)                      // not changed
        print_L(i-1,j-1);
    if (I_L[i][j]==3){                      // replaced
        print_L(i-1, j-1);
        s1[j]=s2[j];//
        cout <<s1<<endl;
    }
    if (I_L[i][j]==2){                      //inserted a character
        print_L(i, j-1);
        s1.insert(j,s2,j,1);
        
        cout << s1<<endl;
    }
    if( I_L[i][j]==0){                       // erased a character
        print_L(i-1,j);
        s1.erase(j+1,1);
        cout <<s1<<endl;
    }
    
}
int main(int argc, const char * argv[]) {
    int n=int(s1.size());
    int m=int(s2.size());
  
    DL.resize(n);
    for(int i=0;i<n;i++)
        DL[i].resize(m,-1);
    
    DDL.resize(n);
    for(int i=0;i<n;i++)
        DDL[i].resize(m,-1);
    I_L.resize(n);
    for(int i=0;i<n;i++)
        I_L[i].resize(m,1);


 
    
    int w1=distance_DL(n-1,m-1);
    int w2=distance_L(n-1,m-1);
    cout << "the distance DL is "<<w1<<endl;
    cout <<"the distance L is "<<w2<<endl;
   
    print_L(n-1,m-1);
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout << I_L[i][j]<<" ";
    }
    cout <<endl;
    }

    return 0;
    
}
