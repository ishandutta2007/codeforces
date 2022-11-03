//
//  main.cpp
//  E1
//
//  Created by  on 16/1/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,p,q;

const int maxn=1e5+5;

int a[maxn];
int b[maxn];

typedef long double LD;

LD ff(LD x){
    LD mv=1;
    for(int i=1;i<=n;i++){
        mv=min(mv,(1-b[i]*x)/a[i]);
    }
    return mv*p+x*q;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&p,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",a+i,b+i);
    }
    LD l=0,r=1.0/(*max_element(b+1,b+1+n));
    for(int i=1;i<=200;i++){
        LD fl=(l+l+r)/3,fr=(r+r+l)/3;
        if(ff(fl)>ff(fr)) r=fr;else l=fl;
    }
    printf("%.10lf\n",(double)ff((l+r)/2));
    return 0;
}