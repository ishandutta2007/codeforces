//
//  main.cpp
//  C
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;

int a[maxn],p[maxn];

int n,m;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]= a[i]==a[i-1] ? p[i-1]: i-1;
    }
    int l,r,x;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&l,&r,&x);
        printf("%d\n",a[r]==x? p[r]>=l? p[r]:-1 :r);
    }
    return 0;
}