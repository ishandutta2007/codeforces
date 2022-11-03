//
//  main.cpp
//  C
//
//  Created by  on 16/1/24.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long x3,y3,x2,y2;

long long n;

long long dis(long long x1,long long y1,long long x,long long y){
    return ((x1-x)*(x1-x)+(y1-y)*(y1-y));
}

const int maxn=2005;

bool vis[maxn];

struct f{
    long long l;
    int id;
}a[maxn],b[maxn];

bool cmp(f a,f b){
    return a.l<b.l;
}

int main(int argc, const char * argv[]) {
    cin>>n;
    cin>>x3>>y3>>x2>>y2;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        long long x4,y4;
        scanf("%I64d%I64d",&x4,&y4);
        a[i].l=dis(x3,y3,x4,y4);
        b[i].l=dis(x2,y2,x4,y4);
        a[i].id=i;
        b[i].id=i;
    }
    //for(int i=1;i<=n;i++){
    //    cout<<a[i].l<<' '<<b[i].l<<endl;
    //}
    a[0].l=0;a[0].id=0;
    b[0].l=0;b[0].id=10000;
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    long long r1=0,r2=0;
    long long ans=1e18;
    for(int i=0;i<=n;i++){
        r1=a[i].l;
        vis[a[i].id]=true;
        r2=0;
        for(int j=0;j<=n;j++){
            if(!vis[b[j].id])
                r2=max(r2,b[j].l);
        }
        if(r1+r2<ans){
            ans=r1+r2;
            //cout<<r1<<' '<<r2<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}