//
//  main.cpp
//  B
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=55;

int a[maxn],b[maxn],c[maxn];

int prea[maxn],sufa[maxn];
int preb[maxn],sufb[maxn];

int n;

int main(int argc, const char * argv[]) {
    cin>>n;
    memset(prea,0,sizeof(prea));
    memset(sufa,0,sizeof(sufa));
    memset(preb,0,sizeof(preb));
    memset(sufb,0,sizeof(sufb));
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        prea[i]=prea[i-1]+a[i];
    }
    for(int i=1;i<n;i++){
        scanf("%d",&b[i]);
        preb[i]=preb[i-1]+b[i];
    }
    for(int i=n-1;i>=1;i--){
        sufa[i]=sufa[i+1]+a[i];
    }
    for(int i=n-1;i>=1;i--){
        sufb[i]=sufb[i+1]+b[i];
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int minx=0x3f3f3f3f,minid1=0;
    int minx2=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int crt=prea[i-1]+c[i]+sufb[i];
        if(crt<minx){
            minx=crt,minid1=i;
        }
    }
    for(int i=1;i<=n;i++){
        int crt=prea[i-1]+c[i]+sufb[i];
        if(i!=minid1){
            minx2=min(minx2,crt);
        }
    }
    //printf("%d %d",minx,minx2);
    printf("%d\n",minx+minx2);
    return 0;
}