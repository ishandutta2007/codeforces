#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAN=1e6+3;
const LL MAX=1e18;
struct milk
{
    int l,r;
    int ls,rs;
    int lens;
    LL sum;
    vector <long long> q;
}t[MAN<<1];
int nam;
int n,m;
LL ans=0;
LL p;
int rin()
{
    int s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void make_tree(int l,int r,int i)
{
    t[i].l=l;t[i].r=r;
    t[i].lens=t[i].r-t[i].l+1;
    t[i].ls=t[i].rs=0;
    t[i].q.push_back(-MAX);//f[0]
    if(l==r)
    {
        t[i].sum=rin();
        t[i].q.push_back(p-t[i].sum);
        t[i].q.push_back(MAX);
        return;
    }
    int mid=(l+r)>>1;
    t[i].ls=++nam;make_tree(l,mid,nam);
    t[i].rs=++nam;make_tree(mid+1,r,nam);
    t[i].sum=t[t[i].ls].sum+t[t[i].rs].sum;
    for(int _=l;_<=r+3;_++)t[i].q.push_back(MAX);
    l=t[i].ls;r=t[i].rs;
    int x,y;
    x=y=0;
    for(;x<=t[l].lens;x++)
    {
        if(y>t[r].lens)y--;
        for(;y<=t[r].lens;y++)
        {
            if(t[l].q[x+1]-1-p*x+t[l].sum<t[r].q[y]){if(y!=0)y--;break;}// x  y 
            t[i].q[x+y]=min(t[i].q[x+y],max(t[l].q[x],t[r].q[y]+p*x-t[l].sum));
        }
    }
    return;
}
inline void cheak(int l,int r,int i)
{
    if(l<=t[i].l&&t[i].r<=r)
    {
        int left=1,right=t[i].r-t[i].l+1;
        int last=0;
        for(;left<=right;)
        {
            int mid=(left+right)>>1;
            if(ans>=t[i].q[mid])last=mid,left=mid+1;
            else right=mid-1;
        }
        ans+=t[i].sum;
        ans-=p*last;
        return;
    }
    if(t[i].ls==0)return;
    if(t[t[i].ls].r>=l)cheak(l,r,t[i].ls);
    if(t[t[i].rs].l<=r)cheak(l,r,t[i].rs);
    return;
}
int main()
{
    int i,j;
    n=rin();m=rin();p=rin();
    nam=1;
    make_tree(1,n,1);
    for(i=1;i<=m;i++)
    {
        int l,r;
        l=rin();r=rin();
        ans=0;
        cheak(l,r,1);
        printf("%lld\n",ans);
    }
    return 0;
}