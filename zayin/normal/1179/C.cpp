#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

const int N=1000005;
int n,m,q;

int a[maxn],b[maxn];

struct node {
    int tag,mn;
} T[maxn<<2];

#define tag(k)  T[k].tag
#define mn(k)   T[k].mn

void renew(int k,int d) {
    tag(k)+=d;
    mn(k)+=d;
}

void godown(int k)  {
    if (!tag(k))    return ;
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void change(int k,int l,int r,int a,int b,int d)    {
    if (a<=l&&r<=b)
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            change(k<<1,l,mid,a,b,d);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,d);
        mn(k)=min(mn(k<<1),mn(k<<1|1));
    }
    // cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<mn(k)<<" "<<tag(k)<<" "<<b<<" "<<d<<endl;
}

int query(int k,int l,int r,int a,int b)   {
    if (l>b||a>r)   return 0;
    // cout<<"query:"<<k<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if (a<=l&&r<=b) return mn(k);
    godown(k);
    int mid=(l+r)>>1;
    return min(query(k<<1,l,mid,a,b),query(k<<1|1,mid+1,r,a,b));
}

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),change(1,1,N,1,a[i],-1);
    for (int i=1;i<=m;++i)
        scanf("%d",b+i),change(1,1,N,1,b[i],1);
    scanf("%d",&q);
    while (q--) {
        int op,i,x;
        scanf("%d%d%d",&op,&i,&x);
        if (op==1)  {
            change(1,1,N,1,a[i],1);
            a[i]=x;
            change(1,1,N,1,a[i],-1);
        }   else    {
            change(1,1,N,1,b[i],-1);
            b[i]=x;
            change(1,1,N,1,b[i],1);
        }

        int l=1,r=N;
        while (l<r) {
            int mid=(l+r)>>1;
            // cout<<mid<<":"<<query(1,1,N,mid,N)<<endl;
            if (query(1,1,N,mid,N)>=0)
                r=mid;
            else
                l=mid+1;
        }
        if (l==1)
            puts("-1");
        else
            printf("%d\n",l-1);
    }
    return 0;
}