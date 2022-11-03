//
//  main.cpp
//  A
//
//  Created by  on 16/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;

const int maxn=1e5+5;


struct point{
    int p,id;
    bool operator < (const point& rhs) const{
        return p<rhs.p;
    }
    int mi,ma;
}d[maxn];

bool cmp(point a,point b){
    return a.id<b.id;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i].p);
        d[i].id=i;
    }
    sort(d+1,d+1+n);
    for(int i=1;i<=n;i++){
        if(i==1){
            d[i].mi=d[2].p-d[1].p;
            d[i].ma=d[n].p-d[1].p;
        }else if(i==n){
            d[i].mi=d[n].p-d[n-1].p;
            d[i].ma=d[n].p-d[1].p;
        }else{
            d[i].mi=min(d[i].p-d[i-1].p,d[i+1].p-d[i].p);
            d[i].ma=max(d[n].p-d[i].p,d[i].p-d[1].p);
        }
    }
    sort(d+1,d+1+n,cmp);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",d[i].mi,d[i].ma);
    return 0;
}