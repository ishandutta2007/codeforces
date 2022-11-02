#include <set>
#include <stdio.h>
#include <algorithm>
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
inline char gc(){char c=getchar();for(;c>'z'||c<'a';c=getchar());return c;}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n,m;
char a[N];
char b[N];
int sl[N];
int sr[N];
set<int>q[26];
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=n;i++)a[i]=gc(),q[a[i]-'a'].insert(i);
    for(int i=1;i<=m;i++)b[i]=gc();
    for(int i=1;i<=m;i++)
    {
        set<int>::iterator j=q[b[i]-'a'].upper_bound(sl[i-1]);
        if(j==q[b[i]-'a'].end())sl[i]=n+1;
        else sl[i]=*j;
    }
    sr[m+1]=n+1;
    for(int i=m;i>=1;i--)
    {
        set<int>::iterator j=q[b[i]-'a'].lower_bound(sr[i+1]);
        if(j==q[b[i]-'a'].begin())sr[i]=0;
        else j--,sr[i]=*j;
    }
    int ans=1;
    for(int i=1;i<m;i++)ans=max(ans,sr[i+1]-sl[i]);
    printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}

//vjudge 