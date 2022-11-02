#include <stdio.h>
#include <queue>
#define LL long long
using namespace std;
const int N=1e5+3;
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

struct gyq
{
    int v,x;
    gyq(int v_=0,int x_=0){v=v_;x=x_;}
};
inline bool operator >(gyq x,gyq y){return x.v>y.v;}
inline bool operator <(gyq x,gyq y){return x.v<y.v;}

int n;
int w[N];
int du[N];
priority_queue<gyq,vector<gyq>,less<gyq> >d;
inline void work()
{
    n=rin();
    LL ans=0;
    for(int i=1;i<=n;i++)w[i]=rin(),ans+=w[i],du[i]=0;
    for(int i=1;i<n;i++){int x=rin(),y=rin();du[x]++;du[y]++;}
    for(int i=1;i<=n;i++)if(du[i]>1)d.push(gyq(w[i],du[i]-1));
    printf("%lld ",ans);
    for(int i=2;i<n;i++)
    {
        if(!d.empty())
        {
            gyq now=d.top();d.pop();
            ans+=now.v;
            now.x--;
            if(now.x)d.push(now);
        }
        printf("%lld ",ans);
    }
    for(;!d.empty();d.pop());
    printf("\n");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}