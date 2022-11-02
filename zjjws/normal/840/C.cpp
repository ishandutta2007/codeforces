#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e2+3;
const int M=32000;
const int Mod=1e9+7;
LL a[N];
int c[N];
int d[M];
int s[M];
bool b[M+3];
LL f[2][N][N];
int tail;
int n;
inline bool myru(int x,int y){return x>y;}
inline bool cheak(LL s){LL p=sqrt(s);return (p*p)!=s;}
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
int main()
{
    int i,j,k;
    for(i=2;i<=M;i++)
    {
        if(!b[i])d[++tail]=i,s[tail]=i*i;
        for(j=1;j<=tail;j++)
        {
            int now=i*d[j];
            if(now>M)break;
            b[now]=true;
            if(i%d[j]==0)break;
        }
    }
    n=rin();
    for(i=1;i<=n;i++){a[i]=rin();for(j=1;j<=tail;j++)for(;a[i]%s[j]==0;a[i]/=s[j]);}
    //
    sort(a+1,a+n+1);
    //  
    int cutt=1;
    memset(f,0,sizeof(f));
    f[1][0][0]=1;
    for(i=2;i<=n;i++)
    {
        bool now=(i&1);
        memset(f[now],0,sizeof(f[now]));
        if(a[i]!=a[i-1])
        {
            for(j=0;j<i-1;j++)
            for(k=0;k<cutt;k++)
            {
                f[now][j][0]+=f[!now][j][k]*(i-j);
                if(j>0)f[now][j-1][0]+=f[!now][j][k]*j;
            }
            for(j=0;j<i;j++)f[now][j][0]%=Mod;
            cutt=1;
            continue;
        }
        for(j=0;j<i;j++)
        {
            int ed=min(cutt,j);
            for(k=0;k<=ed;k++)
            {
                f[now][j][k]+=f[!now][j+1][k]*(j+1-k);
                if(j&&k)f[now][j][k]+=f[!now][j-1][k-1]*((cutt<<1)-k+1);
                f[now][j][k]+=f[!now][j][k]*(i-((cutt<<1)-k)-(j-k));
                f[now][j][k]%=Mod;
            }
        }
        cutt++;
    }
    if(f[n&1][0][0]<0)f[n&1][0][0]+=Mod;
    printf("%lld\n",f[n&1][0][0]);
    return 0;
}