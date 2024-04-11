#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> ed[300000],R[300000];
int dp[300000];int fa[300000];
int in[300000];int ans[300000];

bool ck(int cnt0,int cnt1){return cnt0>=cnt1&&cnt1+1>=cnt0;}

void clear(int n)
{
	for(int i=1;i<=n;i++)ed[i].clear(),R[i].clear(),in[i]=0;
}

bool dfs_bas(int u,int f)
{
	int cnt0=0,cnt1=0;fa[u]=f;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];if(v==f)continue;
		if(!dfs_bas(v,u))return 0;
		if(dp[v])cnt1++;else cnt0++;
	}
	if(f==0){return ck(cnt0,cnt1);}
	if(ck(cnt0+1,cnt1)){dp[u]=0;return 1;}
	if(ck(cnt0,cnt1+1)){dp[u]=1;return 1;}
	return 0;
}

void work()
{
	int n=0;scanf("%d",&n);
	for(int i=1,u=0,v=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);ed[u].push_back(v),ed[v].push_back(u);
	}
	if(!dfs_bas(1,0)){puts("NO");clear(n);return;}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		vector<int> V[2];if(i>=2)V[dp[i]].push_back(i);
		for(int j=0;j<ed[i].size();j++)
		{
			if(ed[i][j]!=fa[i])V[dp[ed[i][j]]].push_back(ed[i][j]);
		}
		vector<int> X;
		for(int j=0;j<V[0].size();j++){X.push_back(V[0][j]);if(j<V[1].size())X.push_back(V[1][j]);}
		for(int i=X.size()-2;i>=0;i--)R[X[i+1]].push_back(X[i]);
	}
	//puts("R");
	for(int i=2;i<=n;i++)for(int j=0;j<R[i].size();j++)in[R[i][j]]++/*,printf("%d %d\n",i,R[i][j])*/;
	//puts("REND");
	queue<int> q;
	for(int i=2;i<=n;i++)if(!in[i])q.push(i);
	int cnt=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();ans[++cnt]=u;
		for(int j=0;j<R[u].size();j++){in[R[u][j]]--;if(!in[R[u][j]])q.push(R[u][j]);}
	}
	for(int i=1;i<n;i++)printf("%d %d\n",ans[i],fa[ans[i]]);
	clear(n);
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)work();
}