#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e5+5;
int n,q;
int a[maxn];
ll sum[maxn];
ll stmx[17][maxn],stmi[17][maxn];
void prework()
{
    for(int i=1;i<=n;i++)stmx[0][i]=stmi[0][i]=sum[i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)stmx[i][j]=max(stmx[i-1][j],stmx[i-1][j+(1<<(i-1))]),stmi[i][j]=min(stmi[i-1][j],stmi[i-1][j+(1<<(i-1))]);
}
ll querymx(int l,int r){int k=log2(r-l+1);return max(stmx[k][l],stmx[k][r-(1<<k)+1]);}
ll querymi(int l,int r){int k=log2(r-l+1);return min(stmi[k][l],stmi[k][r-(1<<k)+1]);}
int main()
{
    n=read();q=read();
    for(int i=1;i<=n;i++)a[i]=-read();
    for(int i=1;i<=n;i++)a[i]+=read();
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    prework();
    while(q--)
    {
        int l=read(),r=read();
        if(sum[l-1]!=sum[r]||querymi(l,r)<sum[l-1])printf("-1\n");
        else printf("%lld\n",querymx(l,r)-sum[l-1]);
    }
    return 0;
}