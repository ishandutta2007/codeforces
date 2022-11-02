#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline int min(int x,int y){return x<y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline int abs(int x){return (x<0)?(-x):(x);}
inline void work()
{
    int n=rin();
    int i;
    if(n<=3)
    {
        for(int i=1;i<=n;i++)printf("%d",8+abs(i-2));
        printf("\n");
        return;
    }
    printf("989");
    for(int i=4;i<=n;i++)printf("%d",(i-4)%10);
    printf("\n");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}