#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gao42(ll x){
    ll t=1;
    while (t<x) t*=42;
    return t-x;
}

int n, q, org[101000];

struct TR{
    ll vl, vr, mn, lat, laz;
}tr[404000];

void U(int x){
    tr[x].mn=min(tr[x<<1].mn,tr[x<<1|1].mn);
    tr[x].vl=min(tr[x<<1].vl,tr[x<<1|1].vl);
    tr[x].vr=max(tr[x<<1].vr,tr[x<<1|1].vr);
}
void PT(int x,ll t,ll z){
    if (t==0){
        tr[x].vl+=z;
        tr[x].vr+=z;
        tr[x].mn-=z;
        tr[x].laz+=z;
    }else{
        tr[x].vl=z;
        tr[x].vr=z;
        tr[x].mn=gao42(z);
        tr[x].lat=1;
        tr[x].laz=z;
    }
}
void D(int x){
    if (tr[x].lat||tr[x].laz){
        PT(x<<1,tr[x].lat,tr[x].laz);
        PT(x<<1|1,tr[x].lat,tr[x].laz);
        tr[x].lat=tr[x].laz=0;
    }
}
void build(int x,int l,int r){
    if (l==r){
        tr[x].vl=tr[x].vr=org[l];
        tr[x].mn=gao42(org[l]);
        return;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    U(x);
}
ll que(int x,int l,int r,int p){
    if (l==r) return tr[x].vl;
    D(x); int mid=l+r>>1;
    if (p<=mid) return que(x<<1,l,mid,p);
    else return que(x<<1|1,mid+1,r,p);
}
ll modif(int x,int l,int r,int st,int en,ll t,ll z){
    st=max(st,l); en=min(en,r);
    if (st>en) return 1;
    if (st==l&&en==r&&(tr[x].vl==tr[x].vr||t==1||t==0&&tr[x].mn>z)){
        PT(x,t,z);
        if (tr[x].vl==tr[x].vr) tr[x].mn=gao42(tr[x].vl);
        return tr[x].mn;
    }
    D(x); int mid=l+r>>1;
    ll res=min(
        modif(x<<1,l,mid,st,en,t,z),
        modif(x<<1|1,mid+1,r,st,en,t,z)
    );
    U(x);
    return res;
}

int main(){
    cin>>n>>q;
    for (int i=1;i<=n;++i) scanf("%d",&org[i]);
    build(1,1,n);
    for (int ty, p, l, r, v;q--;){
        scanf("%d",&ty);
        if (ty==1){
            scanf("%d",&p);
            printf("%lld\n",que(1,1,n,p));
        }else if (ty==2){
            scanf("%d%d%d",&l,&r,&v);
            modif(1,1,n,l,r,1,v);
        }else if (ty==3){
            scanf("%d%d%d",&l,&r,&v);
            while (!modif(1,1,n,l,r,0,v));
        }
    }
}