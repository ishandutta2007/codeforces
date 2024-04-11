#include<cstdio>
#include<algorithm>
#include<iostream>
#define R register
#define lo long long 

using namespace std;

const int gz=1e5+8;

inline void in(R int &x)
{
    int f=1;x=0;char s=getchar();
    while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
    while(isdigit(s)){x=x*10+s-'0';s=getchar();}
    x*=f;
}

int head[gz<<1],tot;

struct cod{int u,v;lo w;}edge[gz<<2];

lo p[64],dis[gz];

inline void add(R int x,R int y,R lo z)
{
    edge[++tot].u=head[x];
    edge[tot].v=y;
    edge[tot].w=z;
    head[x]=tot;
}

int n,m;

bool vis[gz];

inline void ins(R lo x)
{
    for(R int i=63;i>=0;i--)
    {
        if((x>>i)&1LL)
        {
            if(p[i])
                x^=p[i];
            else 
            {
                p[i]=x;
                break;
            }
        }
    }
}

inline lo query(R lo o)
{
    R lo res=o;
    for(R int i=63;i>=0;i--)
        if((res^p[i])<res)res^=p[i];
    return res;
}

void dfs(R int u,R lo now)
{
    vis[u]=true;dis[u]=now;
    for(R int i=head[u];i;i=edge[i].u)
    {
        if(!vis[edge[i].v])
            dfs(edge[i].v,now^edge[i].w);
        else ins(now^edge[i].w^dis[edge[i].v]);
    }
}

int main()
{
    in(n);in(m);
    for(R int i=1,x,y;i<=m;i++)
    {
        R lo z;
        in(x),in(y);
        scanf("%lld",&z);
        add(x,y,z),add(y,x,z);
    }

    dfs(1,0);

    printf("%lld\n",query(dis[n]));
}