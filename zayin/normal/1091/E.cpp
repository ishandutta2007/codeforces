#include<bits/stdc++.h>
#define maxh 20
#define maxn 500050
using namespace std;
typedef long long LL;

int n,d[maxn];

LL sum[maxn];
LL f[maxn],g[maxn];
LL gl[maxn],gr[maxn];

LL L[maxn],R[maxn];

int Log2[maxn]={-1};
LL ST[maxh][maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&d[i]);
}

bool cmp(int i,int j)
{
    return i>j;
}

int find(int D)
{
    if (D<=d[n])    return n+1;
    int l=1,r=n;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (d[mid]>=D)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}

void predo()
{
    sort(d+1,d+n+1,cmp);
    for (int i=1;i<=n;++i)
        f[i]=f[i-1]+d[i];
    for (int i=n;i;--i)
        sum[i]=sum[i+1]+d[i];
    g[n+1]=(LL)n*(n+1);
    for (int i=n;i;--i)
    {
        int j=max(find(i),i+1);
        g[i]=(LL)i*(i-1)+sum[j]+(LL)(j-i-1)*i;
        gl[i]=g[i]+i;
        gr[i]=g[i+1]+min(d[i+1],i+1);
        // cout<<i<<" "<<j<<" "<<f[i]<<" "<<g[i]<<" "<<gl[i]<<" "<<gr[i]<<endl;
    }

    L[0]=1LL<<60;
    for (int i=1;i<=n;++i)
        L[i]=min(L[i-1],gl[i]-f[i]);
    R[n+1]=1LL<<60;
    for (int i=n;i;--i)
        R[i]=min(R[i+1],gr[i]-f[i]);
    
    for (int i=1;i<=n;++i)  Log2[i]=Log2[i>>1]+1;
    for (int i=1;i<=n;++i)  ST[0][i]=g[i]-f[i];
    // for (int i=1;i<=n;++i)
    //     cout<<ST[0][i]<<" ";
    // cout<<endl;
    for (int j=1;(1<<j)<=n;++j)
        for (int i=1;i+(1<<j)-1<=n;++i)
            ST[j][i]=min(ST[j-1][i],ST[j-1][i+(1<<(j-1))]);
            
    // for (int i=1;i<=n;++i)  cout<<d[i]<<" "; cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<f[i]<<" "; cout<<endl;
    // cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<i*(i-1)<<" "; cout<<endl;
    // cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<g[i]<<" "; cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<gl[i]<<" "; cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<gr[i]<<" "; cout<<endl;
    // cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<L[i]<<" "; cout<<endl;
    // for (int i=1;i<=n;++i)  cout<<R[i]<<" "; cout<<endl;
    // cout<<endl;
}

LL Min(int l,int r)
{
    // cout<<"Min:"<<l<<" "<<r<<endl;
    if (l>r)    return 1LL<<60;
    int t=Log2[r-l+1];
    return min(ST[t][l],ST[t][r-(1<<t)+1]);
}

void solve()
{
    int cnt=0;
    for (int D=f[n]&1;D<=n;D+=2)
    {
        bool flag=1;
        int j=find(D);
        // cout<<D<<" "<<j<<" ("<<(f[j-1]+D)<<","<<(g[j]+min(d[j],j))<<")"<<endl;
        if (j<=D)
        {
            flag&=L[j-1]>=0;
        } else
        {
            flag&=L[D]>=0;
            flag&=Min(D+1,j-1)+D>=0;
            // cout<<"chk:"<<Min(D+1,j-1)<<" "<<D<<endl;
        }
        flag&=R[j]>=D;
        flag&=(f[j-1]+D)<=(g[j]+min(d[j],j));
        if (flag)
            ++cnt,printf("%d ",D);
    }
    // cout<<endl;
    // cout<<"cnt:"<<cnt<<endl;
    if (!cnt)
        puts("-1");
}

int main()
{
    init();
    predo();
    solve();
    return 0;
}