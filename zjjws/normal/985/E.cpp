#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=5e5+3;
int n,k,l;
int a[N];
int d[N];
bool f[N];
inline bool myru(int x,int y){return x<y;}
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
int main()
{
    int i,j;
    n=rin();k=rin();l=rin();
    for(i=1;i<=n;i++)a[i]=rin();
    sort(a+1,a+n+1,myru);
    int head=1,tail=0;
    f[0]=true;
    for(i=1,j=0;i<=n;i++)
    {
        if(i>=k&&f[i-k])head=tail+1,d[++tail]=i-k;
        for(;head<=tail&&a[d[head]+1]+l<a[i];head++);
        if(head<=tail)f[i]=true;
    }
    if(f[n])puts("YES");
    else puts("NO");
    return 0;
}