//
//  main.cpp
//  C
//
//  Created by  on 15/11/28.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
string s;
int num[26];

int main(int argc, const char * argv[]) {
    char ch;
    cin>>s;
    int L=s.size();
    memset(num,0,sizeof(num));
    for(int i=0;i<L;i++){
        num[s[i]-97]++;
    }
    int sum=0;
    int end=0;
    for(int i=0;i<26;i++){
        if(num[i]%2==1){
            for(int j=25;j>=0;j--) if(num[j]%2){
                num[i]++;
                num[j]--;
                break;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<=num[i]/2;j++){
            printf("%c",i+97);
        }
    }
    for(int i=0;i<26;i++){
        if(num[i]%2)
            printf("%c",i+97);
    }
    for(int i=25;i>=0;i--){
        for(int j=1;j<=num[i]/2;j++){
            printf("%c",i+97);
        }
    }
    printf("\n");
    return 0;
}