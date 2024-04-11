#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 2e5+20;

int n;
struct adjs{int to,next;}ad[maxn<<1];
int head[maxn],adcnt;
inline void init() {memset(head,-1,sizeof(head)); adcnt=0;}
inline void adde(int a,int b)
{
    ad[adcnt].to=b; ad[adcnt].next=head[a];
    head[a]=adcnt++;
}
int pr[maxn][2];
int col[maxn];

bool dfs(int u,int fa=0)
{
    bool res=1;
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        if(v==fa) continue;
        res &= dfs(v,u) && col[u]==col[v];
    }
    return res;
}

bool check(int u)
{
    int res=1;
    for(int i=head[u];~i;i=ad[i].next)
    {
        int v=ad[i].to;
        res &= dfs(v,u);
    }
    return res;
}

void work()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1,a,b;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            adde(a,b);
            adde(b,a);
            pr[i][0]=a; pr[i][1]=b;
        }

        for(int i=1;i<=n;i++) scanf("%d",&col[i]);

        int tp=0;
        for(int i=1;i<=n;i++) tp+=col[i]!=col[1];

        if(!tp) {puts("YES"); puts("1"); continue;}

        int ans=-1;
        for(int i=1;i<n;i++)
        {
            if(col[pr[i][0]]!=col[pr[i][1]])
            {
                if(check(pr[i][0])) ans=pr[i][0];
                else if(check(pr[i][1])) ans=pr[i][1];
                break;
            }
        }
        if(ans==-1) puts("NO");
        else printf("YES\n%d\n",ans);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    work();
    return 0;
}