#include <stdio.h>
#include <cmath>
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

bool vit[N];
int d[N];
struct gyq
{
    int x,y;
    gyq(int x_=0,int y_=0){x=x_;y=y_;}
}ans[N<<1];
inline void work()
{
    int n=rin();
    if(n<=2){puts("0");return;}
    int tail=0;
    int cutt=0;
    for(int i=1;i<=n;i++)vit[i]=false;
    for(int i=n;i>2;i=ceil(sqrt(i)))vit[i]=true,d[++tail]=i;
    d[++tail]=2;vit[2]=true;
    for(int i=2;i<=n;i++)if(!vit[i])ans[++cutt]=gyq(i,n);
    for(int i=1;i<tail;i++)ans[++cutt]=gyq(d[i],d[i+1]),ans[++cutt]=gyq(d[i],d[i+1]);
    printf("%d\n",cutt);
    for(int i=1;i<=cutt;i++)printf("%d %d\n",ans[i].x,ans[i].y);
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}