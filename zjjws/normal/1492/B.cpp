#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
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
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n;
int a[N];
int b[N];
int c[N];
inline int myru_b(int x,int y){return a[x]>a[y];}
inline void work()
{
    n=rin();
    int lst=n;
    int nam=0;
    for(int i=1;i<=n;i++)a[i]=rin(),b[i]=i;
    sort(b+1,b+n+1,myru_b);
    for(int i=1;i<=n;i++)
    {
        if(b[i]<=lst)
        {
            for(int j=b[i];j<=lst;j++)c[++nam]=a[j];
            lst=b[i]-1;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",c[i]);printf("\n");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 