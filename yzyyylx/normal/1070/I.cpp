#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define N 1210
#define M 100100
using namespace std;

int T,m,n,k,s,t,bb,first[N],ds[N],cur[N],deep[N],a[N],b[N],an[N],ss,ts,ans,tt;
struct Bn
{
	int to,next,quan;
}bn[M];
vector<int>son[N];
queue<int>que;

inline void add(int u,int v,int w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	bn[bb].quan=w;
	first[u]=bb;
}

inline void ad(int u,int v,int w)
{
//	cout<<u<<" "<<v<<" "<<w<<endl;
	add(u,v,w);
	add(v,u,0);
}

inline bool bfs()
{
	int p,q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	que.push(s);
	for(;!que.empty();)
	{
		q=que.front();
		que.pop();
		for(p=first[q];p!=-1;p=bn[p].next)
		{
			if(deep[bn[p].to] || !bn[p].quan) continue;
			deep[bn[p].to]=deep[q]+1;
			que.push(bn[p].to);
		}
	}
	return deep[t];
}

int dfs(int now,int mn)
{
	if(now==t) return mn;
	int res;
	for(int &p=cur[now];p!=-1;p=bn[p].next)
	{
		if(!bn[p].quan || deep[bn[p].to]!=deep[now]+1) continue;
		res=dfs(bn[p].to,min(bn[p].quan,mn));
		if(res)
		{
			bn[p].quan-=res;
			bn[p^1].quan+=res;
			return res;
		}
	}
	return 0;
}

int main()
{
	int i,j,p,q,o,tmp;
	cin>>T;
	while(T--)
	{
		bb=1,ss=ts=0;
		memset(ds,0,sizeof(ds));
		memset(first,-1,sizeof(first));
		memset(an,0,sizeof(an));
		scanf("%d%d%d",&n,&m,&k);
		s=0,t=m+n+1;
//		cout<<s<<" "<<t<<endl;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&p,&q);
			ad(p+m,i,1);
			ad(q+m,i,1);
			ds[p]++,ds[q]++;
		}
		for(i=1;i<=m;i++) ad(i,t,1),ts++;
		for(i=1;i<=n;i++)
		{
			if(ds[i]>k)
				ad(s,i+m,(ds[i]-k)*2),ss+=(ds[i]-k)*2;
		}
//		cout<<" "<<ss<<" "<<ts<<endl<<endl;
		if(i<=n || ss>ts)
		{
			for(i=1;i<=m;i++) printf("0 ");
			puts("");
			continue;
		}
		ans=tt=0;
		for(;bfs();)
		{
			// puts("666");
			for(i=0;i<=t;i++) cur[i]=first[i];
			for(p=dfs(s,INF);p;ans+=p,p=dfs(s,INF));
		}
//		cout<<ans<<endl;
		if(ans<ss)
		{
			for(i=1;i<=m;i++) printf("0 ");
			puts("");
			continue;
		}
		for(i=1;i<=n;i++) son[i].clear();
		for(i=1;i<=m;i++)
		{
			for(p=first[i];p!=-1;p=bn[p].next)
			{
				if(bn[p].to>m&&bn[p].to<=m+n&&bn[p].quan)
				{
					son[bn[p].to-m].push_back(i);
					break;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<son[i].size();j+=2)
			{
				an[son[i][j]]=an[son[i][j+1]]=++tt;
			}
		}
		for(i=1;i<=m;i++)
		{
			if(an[i]) printf("%d ",an[i]);
			else printf("%d ",++tt);
		}
		puts("");
	}
}