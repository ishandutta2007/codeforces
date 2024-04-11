#include<bits/stdc++.h>
#define ans(k)  T[k].ans
#define L(k)    T[k].L
#define R(k)    T[k].R
#define maxm 5
#define maxn 200050
using namespace std;

int n,m,status;

struct node
{
    int ans;
    int L[1<<maxm],R[1<<maxm];
    node () {
        ans=-1;
    }
    node operator * (const node& N) const   {
        if (ans==-1)    return N;
        if (N.ans==-1)  return *this;
        node A;
        A.ans=max(ans,N.ans);
        for (int s=0;s<=status;++s)
        {
            A.L[s]=min(L[s],N.L[s]);
            A.R[s]=max(R[s],N.R[s]);
            A.ans=max(A.ans,max(R[s]-N.L[s],L[s]-N.R[s]));
        }
        return A;
    }
}   T[maxn<<2];

void print(int k,int l,int r)
{
    cout<<k<<" ("<<l<<","<<r<<") "<<ans(k)<<":"<<endl;
    for (int s=0;s<=status;++s)
        cout<<"st :"<<s<<" "<<L(k)[s]<<" "<<R(k)[s]<<endl;
}


void renew(int k)
{
    int pos[maxm];
    for (int i=0;i<m;++i)
        scanf("%d",pos+i);
    ans(k)=0;
    for (int s=0;s<=status;++s)
    {
        int t=0;
        for (int i=0;i<m;++i)
            if (s>>i&1)
                t+=pos[i];
            else
                t-=pos[i];
        L(k)[s]=R(k)[s]=t;
    }
}

void build(int k,int l,int r)
{
    if (l==r)
        renew(k);
    else
    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        T[k]=T[k<<1]*T[k<<1|1];
    }
    // print(k,l,r);
}

void init()
{
    scanf("%d%d",&n,&m);
    status=(1<<m)-1;
    build(1,1,n);
}

void change(int k,int l,int r,int p)
{
    if (l==r)
        renew(k);
    else
    {
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p);
        else
            change(k<<1|1,mid+1,r,p);
        T[k]=T[k<<1]*T[k<<1|1];
    }
}

node query(int k,int l,int r,int a,int b)
{
    if (a>r||l>b)   return node();
    if (a<=l&&r<=b) return T[k];
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)*query(k<<1|1,mid+1,r,a,b);
}

void solve()
{
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int op,i,l,r;
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d",&i);
            change(1,1,n,i);
        } else
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,n,l,r).ans);
        }
    }
}

int main()
{
    init();
    solve();
    return 0;
}