//
//  main.cpp
//  B
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxl = 3e5+10;

char str[maxl];
int num[maxl];

int main(int argc, const char * argv[]) {
    scanf("%s",str+1);
    int l=strlen(str+1);
    memset(num,0,sizeof(num));
    for(int i=1;i<=l;i++)
        num[i]=str[i]-'0';
    long long cnt=0;
    for(int i=1;i<=l;i++){
        if(i==1){
            if(num[i]%4==0) cnt++;
        }else{
            if(num[i]%4==0) cnt++;
            if((num[i-1]*10+num[i])%4==0) cnt+=i-1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}