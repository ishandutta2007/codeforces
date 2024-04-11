#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int n,m;

struct hn{
    pii x;
    int w;
    hn(int _a=0,int _b=0,int _w=0){x.fs=_a,x.sd=_b,w=_w;}
};

bool operator <(hn a,hn b)
{
    if(a.w!=b.w)
        return a.w>b.w;
    return a.x.sd>b.x.sd;
}

priority_queue<hn>q;

vector<pii>g[N];

int d[N][51];

int sqr(int d)
{
    return d*d;
}

void dij()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<=50;j++)
            d[i][j]=1e9;
    q.push(hn(1,0,0));
    d[1][0]=0;
    while(!q.empty())
    {
        hn x=q.top();
        q.pop();
        if(d[x.x.fs][x.x.sd]!=x.w)
            continue;
        for(auto [v,w]:g[x.x.fs])
        {
            if(x.x.sd==0)
            {
                if(x.w<d[v][w])
                    d[v][w]=x.w,q.push(hn(v,w,x.w));
            }
            else
            {
                if(x.w+sqr(x.x.sd+w)<d[v][0])
                    d[v][0]=x.w+sqr(x.x.sd+w),q.push(hn(v,0,d[v][0]));
            }
        }
    }
}

int main()
{  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(mp(v,w));
        g[v].push_back(mp(u,w));
    }
    dij();
    for(int i=1;i<=n;i++)
        printf("%d ",d[i][0]==1e9?-1:d[i][0]);
    puts("");
}