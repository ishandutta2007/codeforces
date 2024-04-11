//
//  main.cpp
//  C
//
//  Created by  on 16/1/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,p;

const int maxn=100005;

int l[maxn],r[maxn];

int num[maxn];

double pi[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        int x=l[i]/p,y=r[i]/p;
        int lr;
        if(x*p<l[i])  lr=(x+1)*p;
        else  lr=l[i];
        int ub=y*p;
        if(ub-lr>=0) num[i]=(ub-lr)/p+1;
        else num[i]=0;
        pi[i]=((double)num[i])/(r[i]-l[i]+1);
    }
    double ans=0;
    for(int i=1;i<n;i++){
        ans+=(pi[i]+pi[i+1]-pi[i]*pi[i+1])*2000;
    }
    ans+=(pi[1]+pi[n]-pi[1]*pi[n])*2000;
    printf("%.8lf\n",ans);
    return 0;
}