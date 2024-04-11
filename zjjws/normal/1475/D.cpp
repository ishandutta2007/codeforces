#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}

const int N=2e5+3;
int n,m;
int a[N];
int b[N];

int q[N];
int p[N];
int t_1,t_2;
inline bool myru(int x,int y){return x>y;}
inline void work()
{
    n=rin();m=rin();
    LL cuts=0;
    for(int i=1;i<=n;i++)a[i]=rin(),cuts+=a[i];
    for(int i=1;i<=n;i++)b[i]=rin();
    if(cuts<m){puts("-1");return;}

    t_1=t_2=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1)q[++t_1]=a[i];
        else p[++t_2]=a[i];
    }
    sort(q+1,q+t_1+1,myru);
    sort(p+1,p+t_2+1,myru);
    LL sum=0;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=t_2;i++)sum+=p[i];
    for(int i=0,j=t_2;i<=t_1;i++)
    {
        sum+=q[i];
        for(;j>0&&sum-p[j]>=m;j--)sum-=p[j];
        if(sum>=m)ans=min(ans,i+(j<<1));
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}