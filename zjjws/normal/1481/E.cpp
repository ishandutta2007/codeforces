#include <stdio.h>
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
    if(bj)s=-s;
    return s;
}
inline int max(int x,int y){return x>y?x:y;}
const int N=5e5+3;

int n;
int a[N];
int l[N];
int r[N];
int cutt[N];

int ls[N];
int rs[N];
int main()
{
    n=rin();
    for(int i=1;i<=n;i++)
    {
        a[i]=rin();
        if(!l[a[i]])l[a[i]]=i;r[a[i]]=i;
    }
    for(int i=n;i>=1;i--)rs[i]=max(rs[i+1],++cutt[a[i]]);
    for(int i=1;i<=n;i++)ls[i]=max(ls[i-1],(i==r[a[i]])?(ls[l[a[i]]-1]+cutt[a[i]]):(0));
    
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,ls[i]+rs[i+1]);
    printf("%d\n",n-ans);
    return 0;
}