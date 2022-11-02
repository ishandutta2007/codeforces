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

struct gyq
{
    int h,w;
    int num;
    inline void Read(int num_){h=rin();w=rin();num=num_;if(h>w)jh(h,w);return;}
}a[N];
inline bool myru(gyq x,gyq y){return x.w<y.w;}

int n;
int nam;
int ans[N];
inline void work()
{
    n=rin();
    for(int i=1;i<=n;i++)a[i].Read(i);
    sort(a+1,a+n+1,myru);
    int minh=0x3f3f3f3f,st=-1;
    for(int i=1,j;i<=n;i=j)
    {
        for(j=i;j<=n&&a[j].w==a[i].w;j++)ans[a[j].num]=(a[j].h>minh)?(st):(-1);
        for(j=i;j<=n&&a[j].w==a[i].w;j++)
        {
            if(a[j].h<minh)minh=a[j].h,st=a[j].num;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}