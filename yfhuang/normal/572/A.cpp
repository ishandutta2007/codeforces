//
//  main.cpp
//  A
//
//  Created by  on 16/2/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int na,nb;
int k,m;

const int maxn=1e5+10;
int a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    cin>>na>>nb;
    cin>>k>>m;
    for(int i=1;i<=na;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=nb;i++){
        scanf("%d",&b[i]);
    }
    if(a[k]<b[nb+1-m]) puts("YES");
    else puts("NO");
    return 0;
}