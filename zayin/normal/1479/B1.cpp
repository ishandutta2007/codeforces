#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,a[maxn];

struct node {
    int val,tag;
} T[maxn<<2];

#define val(k) T[k].val
#define tag(k) T[k].tag

void renew(int k,int d) {
    val(k)+=d;
    tag(k)+=d;
}

void godown(int k)  {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void change_add(int k,int l,int r,int p,int d)    {
    if (l==r) return;
    if (l>p||r<p)
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        change_add(k<<1,l,mid,p,d);
        change_add(k<<1|1,mid+1,r,p,d);
        val(k)=max(val(k<<1),val(k<<1|1));
    }
}

void change(int k,int l,int r,int p,int x)    {
    if (l==r)
        val(k)=max(val(k),x);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p,x);
        else
            change(k<<1|1,mid+1,r,p,x);
        val(k)=max(val(k<<1),val(k<<1|1));
    }
}

int query(int k,int l,int r,int p) {
    if (l>p||r<p) return val(k);
    if (l==r) return 0;
    godown(k);
    int mid=(l+r)>>1;
    return max(query(k<<1,l,mid,p),query(k<<1|1,mid+1,r,p));
}

int query_pos(int k,int l,int r,int p)  {
    if (l==r)
        return val(k);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (p<=mid)
            return query_pos(k<<1,l,mid,p);
        else
            return query_pos(k<<1|1,mid+1,r,p);
    }
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    
    for (int i=1;i<=n;++i)  {
        int t=max(query(1,0,n,a[i])+1,query_pos(1,0,n,a[i]));//change a[i-1]
        tag(1)+=(a[i]!=a[i-1]);
        change(1,0,n,a[i-1],t);
        // cout<<i<<":"<<val(1)<<endl;
    }

    printf("%d\n",val(1));
    return 0;
}