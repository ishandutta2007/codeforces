#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

struct node {
    int tag,len;
    int cnt;
} T[maxn<<2];
#define len(k) T[k].len
#define tag(k) T[k].tag
#define cnt(k) T[k].cnt

int n,m;
char s[maxn],t[maxn];

void update(int k)  {
    cnt(k)=cnt(k<<1)+cnt(k<<1|1);
}

void renew(int k,int d) {
    tag(k)=d;
    cnt(k)=len(k)*d;
}

void godown(int k)  {
    if (!~tag(k)) return ;
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=-1;
}

void build(int k,int l,int r)   {
    len(k)=r-l+1;
    tag(k)=-1;
    if (l==r)
        cnt(k)=t[l]-'0';
    else    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        update(k);
    }
}

void change(int k,int l,int r,int a,int b,int d)    {
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<d<<endl;
    if (a<=l&&r<=b)
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        update(k);
    }
}

int query(int k,int l,int r,int a,int b)    {
    if (a>r||l>b) return 0;
    if (a<=l&&r<=b) return cnt(k);
    godown(k);
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)+query(k<<1|1,mid+1,r,a,b);
}

bool travel(int k,int l,int r)  {
    if (l==r) return (s[l]-'0')==cnt(k);
    godown(k);
    int mid=(l+r)>>1;
    return travel(k<<1,l,mid)&&travel(k<<1|1,mid+1,r);
}

int L[maxn],R[maxn];

bool solve()    {
    build(1,1,n);
    for (int i=m;i;--i) {
        int cnt1=query(1,1,n,L[i],R[i]),cnt0=R[i]-L[i]+1-cnt1;
        // cout<<i<<":"<<cnt0<<" "<<cnt1<<endl;
        if (cnt0<=(R[i]-L[i])/2)
            change(1,1,n,L[i],R[i],1);
        else
        if (cnt1<=(R[i]-L[i])/2)
            change(1,1,n,L[i],R[i],0);
        else
            return 0;
    }
    return travel(1,1,n);
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%s%s",&n,&m,s+1,t+1);
        for (int i=1;i<=m;++i)
            scanf("%d%d",L+i,R+i);
        puts(solve()?"YES":"NO");
    }
    return 0;
}