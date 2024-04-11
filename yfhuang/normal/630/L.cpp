//
//  main.cpp
//  12
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    char num[6];
    cin>>num;
    long long a=10000*(num[0]-'0')+1000*(num[2]-'0')+100*(num[4]-'0')+10*(num[3]-'0')+num[1]-'0';
    long long ans=1;
    for(int i=1;i<=5;i++){
        ans*=a;
        ans%=100000;
    }
    for(int i=10000;i>=1;i/=10){
        if(ans>=i) printf("%c",ans/i+'0');
        else printf("0");
        ans%=i;
    }
    return 0;
}