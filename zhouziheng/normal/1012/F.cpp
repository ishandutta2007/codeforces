#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;


struct ctr
{
	int s,len,t;
}C[30];

int id_t[30],id_s[30];
bool scmp(int x,int y){return C[x].s<C[y].s;}
bool tcmp(int x,int y){return C[x].t<C[y].t;}

const long long INF=1e15;

long long dp[1<<22];int way[1<<22];

typedef pair<int,long long> PI;
vector<PI> Q,R;vector<long long> X;

long long ans[30][2];

int main()
{
	int n=0,p=0;scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)scanf("%d%d%d",&C[i].s,&C[i].len,&C[i].t);
	for(int i=0;i<n;i++)id_t[i]=id_s[i]=i;
	sort(id_t,id_t+n,tcmp),sort(id_s,id_s+n,scmp);
	
	dp[0]=1;for(int i=1;i<(1<<n);i++)dp[i]=INF;
	for(int i=0;i<(1<<n)-1;i++)
	{
		if(dp[i]==INF)continue;
		int lastq=dp[i],lastr=dp[i];Q.clear(),R.clear(),X.clear();
		X.push_back(dp[i]);
		for(int j=0;j<n;j++)
		{
			int u=id_s[j];
			if(C[u].s+C[u].len<dp[i])continue;
			X.push_back(C[u].s+C[u].len);
			if(i&(1<<u))
			{
				Q.push_back(make_pair(lastq,max(C[u].s-lastq,0)));
				lastq=C[u].s+C[u].len;
			}
			else
			{
				R.push_back(make_pair(lastr,max(C[u].s-lastr,0)));
				lastr=C[u].s+C[u].len;
			}
		}
		Q.push_back(make_pair(lastq,INF)),R.push_back(make_pair(lastr,INF));
		//printf("D: %d\n",i);
		//for(int i=0;i<Q.size();i++)printf("%d %lld\n",Q[i].first,Q[i].second);
		//for(int i=0;i<R.size();i++)printf("%d %lld\n",R[i].first,R[i].second);
		//for(int i=0;i<X.size();i++)printf("%lld\n",X[i]);
		int posq=0,posr=0,posx=0;
		for(int j=0;j<n;j++)
		{
			int u=id_t[j];if(i&(1<<u))continue;
			while(!(X[posx]>=Q[posq].first&&X[posx]+C[u].t<Q[posq].first+Q[posq].second
			&&X[posx]>=R[posr].first&&X[posx]<R[posr].first+R[posr].second))
			{
				posx++;
				while(Q[posq].first+Q[posq].second<=X[posx])posq++;
				while(R[posr].first+R[posr].second<=X[posx])posr++;
			}
			int v=i|(1<<u);
			//printf("%d %d\n",u,posx);
			if(X[posx]+C[u].t<C[u].s&&dp[v]>X[posx]+C[u].t){dp[v]=X[posx]+C[u].t;way[v]=u;}
		}
	}
	//for(int i=0;i<(1<<n);i++)printf("%lld %d\n",dp[i],way[i]);
	if(p==1)
	{
		if(dp[(1<<n)-1]==INF)puts("NO");
		else
		{
			puts("YES");int u=(1<<n)-1;
			while(u)
			{
				ans[way[u]][0]=dp[u]-C[way[u]].t;u^=(1<<way[u]);
			}
			for(int i=0;i<n;i++)printf("%d %lld\n",1,ans[i][0]);
		}
	}
	else
	{
		bool flag=0;
		for(int i=0;i<(1<<n);i++)
		{
			if(dp[i]!=INF&&dp[((1<<n)-1)^i]!=INF)
			{
				flag=1;int u=i;
				while(u)
				{
					ans[way[u]][0]=dp[u]-C[way[u]].t,ans[way[u]][1]=1;u^=(1<<way[u]);
				}
				u=((1<<n)-1)^i;
				while(u)
				{
					ans[way[u]][0]=dp[u]-C[way[u]].t,ans[way[u]][1]=2;u^=(1<<way[u]);
				}
				break;
			}
		}
		puts(flag?"YES":"NO");
		if(flag)for(int i=0;i<n;i++)printf("%lld %lld\n",ans[i][1],ans[i][0]);
	}
}