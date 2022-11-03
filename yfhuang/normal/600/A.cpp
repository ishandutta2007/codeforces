//
//  main.cpp
//  A
//
//  Created by  on 15/11/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s;
string str;
string alp,num;

bool is_number(char ch){
    return ch>=48&&ch<=57;
}

int main(int argc, const char * argv[]) {
    str=";";
    cin>>s;
    str+=s;
    str+=";";
    alp="";num="";
    //cout<<str<<endl;
    //printf("%d ",isdigit('0'));
    //int prepos=-1,pos=0;
    //int point=0;
    //printf("%d",str.size());
    string t="";
    for(int i=1;i<str.size();i++){
        //`cout<<t;
        if(str[i]==','||str[i]==';'){
            if(t.length()==0) alp+=",";
            else{
                string tt="";
                bool is_num=true;
                for(int j=0;j<t.length();j++){
                    if(isdigit(t[j])){
                        tt+=t[j];
                    }
                    else is_num=false;
                }
                //printf("%d ",is_num);
                if(t=="0") is_num=true;
                else if(t.length()>=2&&t[0]=='0') is_num=false;
                //printf("%d ",is_num);
                if(is_num){
                    num+=tt;
                    num+=',';
                }
                else{
                    alp+=t;
                    alp+=',';
                }
            }
            t="";
        }
        else t+=str[i];
        //cout<<t<<endl;
    }
    if(num.size()==0) printf("-\n");
    else{
        printf("\"");
        for(int i=0;i<num.size()-1;i++){
            printf("%c",num[i]);
        }
        printf("\"\n");
    }
    if(alp.size()==0) printf("-\n");
    else{
        printf("\"");
        for(int i=0;i<alp.size()-1;i++){
            printf("%c",alp[i]);
        }
        printf("\"");
    }

    return 0;
}