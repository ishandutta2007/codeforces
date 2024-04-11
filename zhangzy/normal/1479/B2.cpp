#include <bits/stdc++.h>
#define ll long long
using namespace std;



int n, m=1e5+1, a[101000], tr[404000], laz[404000];

void U(int x){
    tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
void PT(int x,int v){
    tr[x]+=v;
    laz[x]+=v;
}
void D(int x){
    if (laz[x]){
        PT(x<<1,laz[x]);
        PT(x<<1|1,laz[x]);
        laz[x]=0;
    }
}

void cg(int x,int l,int r,int p,int v){
    if (l==r){
        tr[x]=min(tr[x],v);
        return;
    }
    D(x); int mid=l+r>>1;
    if (p<=mid) cg(x<<1,l,mid,p,v);
    else cg(x<<1|1,mid+1,r,p,v);
    U(x);
}

void add(int x,int l,int r,int st,int en,int v){
    st=max(st,l); en=min(en,r);
    if (st>en) return;
    if (st==l&&en==r){
        PT(x,v);
        return;
    }
    D(x); int mid=l+r>>1;
    add(x<<1,l,mid,st,en,v);
    add(x<<1|1,mid+1,r,st,en,v);
}

int que(int x,int l,int r,int st,int en){
    st=max(st,l); en=min(en,r);
    if (st>en) return 1e9;
    if (st==l&&en==r){
        return tr[x];
    }
    D(x); int mid=l+r>>1;
    return min(
        que(x<<1,l,mid,st,en),
        que(x<<1|1,mid+1,r,st,en)
    );
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    memset(tr,33,sizeof tr);
    int now=a[1];
    cg(1,1,m,m,1);
    for (int i=2;i<=n;++i){
        int x=a[i];
        if (x==now){
            int v=min(que(1,1,m,1,x-1),que(1,1,m,x+1,m));
            cg(1,1,m,x,v+1);
        }else{
            int v=min(que(1,1,m,1,x-1),que(1,1,m,x+1,m));
            int w=que(1,1,m,x,x);
            add(1,1,m,1,m,1);
            cg(1,1,m,now,v+1);
            cg(1,1,m,now,w);
        }
        now=x;
    }
    cout<<que(1,1,m,1,m)<<endl;
}