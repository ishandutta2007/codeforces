//
//  main.cpp
//  E
//
//  Created by  on 16/1/24.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn=1e5+5;
typedef long long ll;
int n,m,k;
int a[maxn],pre[maxn];
ll mp[1<<20];
ll res[maxn];
ll sz;

struct qnode{
    int l,r,id;
}qu[maxn];

bool cmp(qnode a,qnode b){
    if(a.l/sz==b.l/sz){
        return a.r<b.r;
    }
    return a.l/sz<b.l/sz;
}

void work(int m,int k){
    ll now=0;
    int pl=1,pr=0;
    mp[a[pl-1]]++;
    for(int i=0;i<m;i++){
        while(pr<qu[i].r){
            pr++;
            now+=mp[pre[pr]^k];
            mp[pre[pr]]++;
        }
        while(pl>qu[i].l)
        {
            pl--;
            now+=mp[pre[pl-1]^k];
            mp[pre[pl-1]]++;
        }
        while(pr>qu[i].r)
        {
            mp[pre[pr]]--;
            now-=mp[pre[pr]^k];
            pr--;
        }
        while(pl<qu[i].l)
        {
            mp[pre[pl-1]]--;
            now-=mp[pre[pl-1]^k];
            pl++;
        }
        res[qu[i].id]=now;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&m,&k);
    sz=ceil(sqrt(1.0*n));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=0;
    for(int i=1;i<=n;i++){
        if(i==1)pre[i]=a[i];
        else{
            pre[i]=pre[i-1]^a[i];
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].id=i;
    }
    sort(qu,qu+m,cmp);
    work(m,k);
    for(int i=0;i<m;i++)
        printf("%I64d\n",res[i]);
    return 0;
}