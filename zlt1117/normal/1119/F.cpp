#include <vector>
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
const int maxn=3e5+5;
const ll inf=1e18;
int ind[maxn],now,n;
using namespace std;
set<pair<int,int>>e[maxn];
vector<ll>answers;
bool vis[maxn]; 
ll dp[maxn][2];
struct node
{
	int u,val;
	inline bool operator < (const node &b)const{return val>b.val;}
};
priority_queue<node>pq;
set<int>S;
bool cur[maxn];
multiset<ll>q[maxn];
ll val[maxn];
inline void dfs(int u,int fa)
{
	///dp[u][0] can choose u->fa
	///dp[u][1] can't choose u->fa
	vis[u]=1;
	vector<ll>vec;
	ll sum=0;
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa||cur[v])continue;
		dfs(v,u);
		sum+=dp[v][1];
		vec.pb(dp[v][0]-dp[v][1]+w);
	}
//	for(auto x:q[u])vec.pb(x);
	int cnt=0;
	int now=::now-(ind[u]-sz(q[u])-sz(e[u]));
	auto it=q[u].end();
	while(1)
	{
		if(it==q[u].begin())break;
		it--;
		int x=*it; 
		if(cnt>=sz(e[u])||cnt>=now)break;
		cnt++;vec.pb(x);
	}
	sort(vec.begin(),vec.end(),greater<ll>());
	FOR(i,0,now-2)if(vec[i]>=0)dp[u][0]+=vec[i];dp[u][1]=dp[u][0];
	if(now>0&&vec[now-1]>=0)dp[u][1]+=vec[now-1];
	dp[u][0]+=sum,dp[u][1]+=sum;
}
std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
	//cerr<<N<<endl;
	answers.resize(N);n=N;	
	ll nowval=0;
	FOR(i,0,N-2)
	{
		U[i]++,V[i]++;
		e[U[i]].insert({V[i],W[i]});
		e[V[i]].insert({U[i],W[i]});
		ind[U[i]]++,ind[V[i]]++;nowval+=W[i];
	}
	FOR(i,1,n)pq.push({i,ind[i]});
	FOR(i,1,n)S.insert(i);
	int maxind=0;
	FOR(i,1,n)maxind=max(maxind,ind[i]);
	FOR(i,0,n-1)
	{
		now=i;if(now>maxind)break;
		for(int j:S)
		{
			dp[j][0]=dp[j][1]=0,vis[j]=0;
			while(sz(q[j])>ind[j]-now&&sz(q[j]))
			{
				val[j]-=*--q[j].end();
				nowval-=*--q[j].end();
				q[j].erase(--q[j].end());
			}
		}
		vector<node>tmp;
		while(!pq.empty())
		{
			auto x=pq.top();
			if(x.val<=now)
			{
				tmp.pb(x);
				cur[x.u]=1;
				for(auto it=e[x.u].begin();it!=e[x.u].end();)
				{
					auto xx=*it;it++;
					if(!cur[xx.first])
					{
						e[x.u].erase(e[x.u].lower_bound({xx.first,0}));
						e[xx.first].erase(e[xx.first].lower_bound({x.u,0}));
						q[xx.first].insert(xx.second);
						val[xx.first]+=xx.second;
					}
				}
			}
			else break;	
			pq.pop();
		} 
		for(int j:S)
		{
			dp[j][0]=dp[j][1]=0,vis[j]=0;
			while(sz(q[j])>ind[j]-now&&sz(q[j]))
			{
				val[j]-=*--q[j].end();
				nowval-=*--q[j].end();
				q[j].erase(--q[j].end());
			}
		}
		for(auto x:tmp)S.erase(x.u);
		//printf("%d\n",nowval);
		//FOR(i,1,n)printf("%d %d\n",i,val[i]);
		//for(int x:S)printf("%d ",x);puts("");
		now=i;
		for(int x:S)if(!vis[x])
		dfs(x,0),answers[i]+=max(dp[x][0],dp[x][1]);
		//printf("%d\n",answers[i]);
		answers[i]=nowval-answers[i];
	}
	return answers;
}

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
//	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
    U[i]--,V[i]--;
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}