//
//  main.cpp
//  B
//
//  Created by  on 15/12/24.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=200000+30;

char str1[maxn];
char str2[maxn];

int f[maxn][2];

int main(int argc, const char * argv[]) {
    scanf("%s",str1);
    scanf("%s",str2);
    int L=strlen(str2);
    int l=strlen(str1);
    memset(f,0,sizeof(f));
    for(int i=0;i<L;i++){
        if(str2[i]-'0'==0) {f[i+1][0]=f[i][0]+1;f[i+1][1]=f[i][1];}
        else {f[i+1][0]=f[i][0];f[i+1][1]=f[i][1]+1;}
    }
   // for(int i=0;i<L;i++){
   //     printf("%d %d ",f[i][0],f[i][1]);
   // }
    long long sum=0;
    for(int i=0;i<l;i++){
        int a=abs(str1[i]-'0')*(f[L-l+1+i][0]-f[i][0])+abs(str1[i]-'0'-1)*(f[L-l+1+i][1]-f[i][1]);
        //printf("%d ",a);
        sum+=a;
    }
    printf("%I64d\n",sum);
}