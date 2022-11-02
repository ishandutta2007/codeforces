#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
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
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=3e5+3;
const int K=53;
int n,m;

struct gyq
{
    int to,nxt;
    LL val;
    gyq(int to_=0,int nxt_=0,LL val_=0){to=to_;nxt=nxt_;val=val_;}
}a[N<<1];
int nam;
int h[N];
inline void add(int x,int y,LL z){a[++nam]=gyq(y,h[x],z);h[x]=nam;return;}

LL dis[N][K];
bool tag[N][K];

struct zjj
{
    LL lens;
    int num,sk;
    zjj(int num_=0,int sk_=0,LL lens_=0){num=num_;sk=sk_;lens=lens_;}
    inline bool operator <(const zjj& y)const{return lens>y.lens;}
};
priority_queue<zjj>q;

inline LL powd(LL x){return x*x;}
inline void work()
{
    n=rin();m=rin();
    for(int i=1;i<=m;i++)
    {
        int x=rin(),y=rin();
        LL z=rin();
        add(x,y,z);
        add(y,x,z);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1][0]=0;
    q.push(zjj(1,0,0));
    for(;!q.empty();)
    {
        zjj now=q.top();q.pop();
        if(tag[now.num][now.sk])continue;
        if(now.sk)
        {
            int st=now.num;
            for(int i=h[st];i;i=a[i].nxt)
            {
                int to=a[i].to;
                if(dis[to][0]>now.lens+powd(now.sk+a[i].val))
                {
                    dis[to][0]=now.lens+powd(now.sk+a[i].val);
                    if(!tag[to][0])q.push(zjj(to,0,dis[to][0]));
                }
            }
        }
        else
        {
            int st=now.num;
            for(int i=h[st];i;i=a[i].nxt)
            {
                int to=a[i].to;
                if(dis[to][a[i].val]>now.lens)
                {
                    dis[to][a[i].val]=now.lens;
                    q.push(zjj(to,a[i].val,dis[to][a[i].val]));
                }
            }
        }
        tag[now.num][now.sk]=true;
    }
    return;
}
inline void pri()
{
    for(int i=1;i<=n;i++)if(dis[i][0]>3e14)printf("-1 ");else printf("%d ",dis[i][0]);
    printf("\n");
    return;
}
int main()
{
    work();
    pri();
    return 0;
}

//vjudge 