//
//  main.cpp
//  B
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int h,m;
int a;
int ha,ma;

int main(int argc, const char * argv[]) {
    scanf("%d:%d",&h,&m);
    scanf("%d",&a);
    ha=a/60,ma=a%60;
    h+=(m+ma)/60;
    m=(m+ma)%60;
    h=(h+ha)%24;
    char str[6];
    if(h<10){
        str[0]='0';
        str[1]='0'+h%10;
    }else{
        str[0]='0'+h/10;
        str[1]='0'+h%10;
    }
    if(m<10){
        str[3]='0';
        str[4]='0'+m%10;
    }else{
        str[3]='0'+m/10;
        str[4]='0'+m%10;
    }
    str[2]=':';
    str[5]='\0';
    printf("%s\n",str);
    return 0;
}