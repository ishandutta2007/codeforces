#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=1e2+3;
int a[N];
int n;
inline int min(int x,int y){return x<y?x:y;}
inline bool myru(int x,int y){return x<y;}
inline int abs(int x){return (x<0)?(-x):(x);}
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
    n=rin();
    int m=(n>>1);
    for(i=1;i<=m;i++)a[i]=rin();
    sort(a+1,a+m+1,myru);
    int ans=0;
    for(i=1;i<=m;i++)ans+=abs(a[i]-(i<<1)+1);
    int sum=0;
    for(i=1;i<=m;i++)sum+=abs(a[i]-(i<<1));
    printf("%d\n",min(ans,sum));
    return 0;
}