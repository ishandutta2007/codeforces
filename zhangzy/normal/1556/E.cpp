#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll mx, mn, sum;
}nd[404000];
node nil={0,0,0};

node operator + (node a, node b){
    return {
        max(a.mx,b.mx+a.sum),
        min(a.mn,b.mn+a.sum),
        a.sum+b.sum
    };
}

int n, q, a[101000], b[101000];

void build(int x,int l,int r){
    if (l==r){
        int v=b[l]-a[l];
        nd[x]={max(v,0),min(v,0),v};
        return;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    nd[x]=nd[x<<1]+nd[x<<1|1];
}
node que(int x,int l,int r,int st,int en){
    st=max(st,l); en=min(en,r);
    if (st>en) return nil;
    if (st==l&&en==r){
        return nd[x];
    }
    int mid=l+r>>1;
    return que(x<<1,l,mid,st,en) + que(x<<1|1,mid+1,r,st,en);
}

int main(){
    cin>>n>>q;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i) scanf("%d",&b[i]);
    build(1,1,n);
    for (int l,r;q--;){
        scanf("%d%d",&l,&r);
        node t = que(1,1,n,l,r);
        if (t.mn<0||t.sum!=0){
            puts("-1");
            continue;
        }
        printf("%lld\n",t.mx);
    }
}