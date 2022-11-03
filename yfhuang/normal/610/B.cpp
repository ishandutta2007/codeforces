//
//  main.cpp
//  B
//
//  Created by  on 15/12/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn=2e5+5;
const int INF=0x3fffffff;

long long a[2*maxn];

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    long long minx=INF;
    for(int i=1;i<=n;i++){
        minx=min(minx,a[i]);
    }
    for(int i=n+1;i<=2*n;i++){
        a[i]=a[i-n];
    }
    long long maxl=0;
    int l=0;
    long long beg=0;
    for(int i=1;i<=2*n;i++){
        if(a[i]>minx&&beg==0){
            beg=i;
        }
        if(a[i]==minx&&beg!=0){
            maxl=max(i-beg,maxl);
            beg=0;
        }
    }
    if(beg) maxl=max(2*n+1-beg,maxl);
    long long ans=minx*n+maxl;
    cout<<ans<<endl;
    return 0;
}