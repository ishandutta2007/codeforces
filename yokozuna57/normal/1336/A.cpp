#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int n,k;
vector<int> G[200010];

ll cnt[200010];
ll dep[200010];
void dfs(int v,int p,int d){
	cnt[v]=1;
	dep[v]=d;
	for(int u: G[v]){
		if(u==p)continue;
		dfs(u,v,d+1);
		cnt[v]+=cnt[u];
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0,1);
	
	ll ret=0;
	priority_queue<P> que;
	que.push(P(cnt[1]-dep[1],1));
	for(int i=0;i<n-k;i++){
		P p=que.top(); que.pop();
		ret+=p.fr;
		for(int v: G[p.sc]){
			if(dep[v]>dep[p.sc]){
				que.push(P(cnt[v]-dep[v],v));
			}
		}
	}
	cout<<ret<<endl;
}