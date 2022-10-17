#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,st[N],ed[N],dc;

struct Edge{
	int v,w;
};

int d[N],s,done[N],fd[N];

vector<Edge>e[N];

struct node{
	int d,x;
};

bool operator >(node a,node b)
{
	return a.d>b.d;
}

priority_queue<node,vector<node>,greater<node> >q;

int anc[N][21];

int p[N],mxd;

int dfs(int x,int f)
{
    st[x]=++dc;
    anc[x][0]=f;
    for(int j=1;j<=20;j++)
        anc[x][j]=anc[anc[x][j-1]][j-1];
    int a=d[x],b=d[x];
    for(auto [v,w]:e[x])
    {
        if(v==f)
            continue;
        int dv=dfs(v,x);
        if(dv>a)
            b=a,a=dv;
        else if(dv>b)
            b=dv;
    }
    p[b-1]=max(p[b-1],a+b-d[x]*2);
    ed[x]=dc;
    return a;
}

int lca(int x,int y)
{
    if(d[x]<d[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if(d[x]-(1<<i)>=d[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

void dijkstra()
{
	for(int i=1;i<=n;i++)
		d[i]=0x7fffffff,done[i]=0;
	d[s]=0;
	node tmp;
	tmp.x=s,tmp.d=d[s];
	q.push(tmp);
	while(!q.empty())
	{
		node i=q.top();
		q.pop();
		int x=i.x;
		if(done[x])
			continue;
		done[x]=1;
		for(int j=0;j<e[x].size();j++)
		{
			int v=e[x][j].v;
			if(d[v]>d[x]+e[x][j].w)
			{
				d[v]=d[x]+e[x][j].w;
				tmp.x=v,tmp.d=d[v];
				q.push(tmp);
			}
		}
	}
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        dc=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            e[i].clear(),p[i]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back({v,1});
            e[v].push_back({u,1});
        }
        s=1;
        dijkstra();
        mxd=*max_element(d+1,d+n+1);
        dfs(1,0);
        for(int i=mxd-1;i>=0;i--)
            p[i]=max(p[i],p[i+1]);
        for(int dd=1;dd<=n;dd++)
        {
            int l=0,r=mxd;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                int fdis=p[mid];
                if((fdis+1)/2+dd<=mid)
                    r=mid;
                else
                    l=mid;
            }
            printf("%d%c",r," \n"[dd==n]);
        }
    }
}