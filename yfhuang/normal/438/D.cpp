//
//  main.cpp
//  D
//
//  Created by  on 2017/3/26.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;

const int maxn = 1e5 + 5;

int maxv[maxn << 2];
long long sumv[maxn << 2];
int a[maxn];

void build(int o,int l,int r){
    if(l == r){
        maxv[o] = a[l];
        sumv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1; build(o * 2,l,mid);build(o * 2 + 1,mid + 1,r);
    maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
    sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}

void update(int o,int l,int r,int p,int v){
    if(l == r){
        maxv[o] = v;
        sumv[o] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(o * 2,l,mid,p,v);
    else update(o * 2 + 1,mid + 1,r,p,v);
    maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
    sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}

void gao(int o,int l,int r,int ql,int qr,int x){
    if(ql > r || l > qr || maxv[o] < x) return;
    if((ql <= l && r <= qr) && l == r){
        maxv[o] %= x;
        sumv[o] %= x;
        return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid) gao(o * 2,l,mid,ql,qr,x);
    if(qr > mid) gao(o * 2 + 1,mid + 1,r,ql,qr,x);
    maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
    sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}

long long query(int o,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        return sumv[o];
    }
    int mid = (l + r) >> 1;
    long long ans = 0;
    if(ql <= mid) ans += query(o * 2,l,mid,ql,qr);
    if(qr > mid) ans += query(o * 2 + 1,mid + 1,r,ql,qr);
    return ans;
}



int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    build(1,1,n);
    for(int i = 1;i <= m;i++){
        int type;
        scanf("%d",&type);
        if(type == 1){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,1,n,l,r));
        }else if(type == 2){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            gao(1,1,n,l,r,x);
        }else{
            int p,v;
            scanf("%d%d",&p,&v);
            update(1,1,n,p,v);
        }
    }
    return 0;
}