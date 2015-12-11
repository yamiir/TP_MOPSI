//
//  command_line.hpp
//  TP6_DING_Hongyang
//
//  Created by dhy on 10/12/15.
//  Copyright © 2015 dhy. All rights reserved.
//

#ifndef command_line_hpp
#define command_line_hpp

#include <stdio.h>
#include <string>
#include <vector>
namespace command{
    class Option{
    protected:
        char shortNameChar;
        std::string fullName;
    public:
        virtual Option *clone() = 0;
        virtual ~Option(){
        bool check(char* arg);// check if the name is arg
        };
        virtual bool decode(int &argc, char *argv[])=0;
    };
    
    
    template <typename T>
    class OptionField:Option{
        T *value;
    public:
        OptionField(char shortN, std::string fullN,T &para){
            shortNameChar=shortN;
            fullName=fullN;
            value=&para;
        }
        virtual Option* clone()const{
            return new OptionField<T> (*this);
        }
        virtual bool decode(int &argc, char*argv[]){
            
        }
    };
    template<>
    bool OptionField<bool>::decode(int &argc, char*argv[]){
        
    };
    template<typename T>
    bool OptionField<T>::decode(int &argc, char*argv[]){
        
    };

    class CmdLine{
        std::vector<Option *> options;
    public:
        void add(Option op);
        ~CmdLine(){
            for(it)//delete options
                delete *it;
        };
        void process(int&argc, char*argv[]){
            for(it)
                if(it->check(arg)){
                    
                }
        }
    };

    template <typename T>
    OptionField <T> make_option(char shortNameChar,char*fullName,T& para){
        return OptionField<T>(shortNameChar, fullName,para);
    }
}
#endif /* command_line_hpp */
