#include <stdio.h>
#define LL long long
using namespace std;
const int N=1e5+3;
int n,k;
inline int min(int x,int y){return x<y?x:y;}
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

int a[N];
inline void work()
{
    n=rin();k=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    int ans=0x3f3f3f3f;
    for(int j=1;j<=100;j++)
    {
        int last=-0x3f3f3f3f,cutt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=j)
            {
                if(last+k-1<i)last=i,cutt++;
            }
        }
        ans=min(ans,cutt);
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}