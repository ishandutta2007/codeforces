//
//  main.cpp
//  D
//
//  Created by  on 15/11/21.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[10000][2];

int main(int argc, const char * argv[]) {
    long long x;
    cin>>x;
    long long j;
    int p=0;
    for(long long i=1;;i++){
        if(i*(i+1)/2*(2*i+1)/3>x) break;
        if((3*x)%(i*(i+1)/2)==0&&((3*x)/(i*(i+1)/2)+i-1)%3==0) {j=(3*x/(i*(i+1)/2)+i-1)/3;a[++p][0]=i;a[p][1]=j;}
    }
    if(a[p][0]==a[p][1]) printf("%d\n",2*p-1);
    else printf("%d\n",2*p);
    for(int i=1;i<=p;i++){
        printf("%I64d %I64d\n",a[i][0],a[i][1]);
    }
    if(a[p][0]==a[p][1]){
        for(int i=p-1;i>=1;i--){
            printf("%I64d %I64d\n",a[i][1],a[i][0]);
        }
    }
    else{
        for(int i=p;i>=1;i--){
            printf("%I64d %I64d\n",a[i][1],a[i][0]);
        }
    }
    return 0;
}