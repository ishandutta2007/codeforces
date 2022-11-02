#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = 1000+10;
const int MAX_M = 20000 + 10;
typedef long long ll;
const ll inf = 1LL<<50;

int n,m,L,s,t;
vector<int> edge[MAX_N];
int to[MAX_M];
ll cost[MAX_M];

vector<int> erased_a,erased_b;

ll check(ll add){
	if(!erased_a.empty()){
		int cnt = erased_a.size();
		int rem = add % cnt;
		rep(i,0,cnt){
			int a = erased_a[i], b = erased_b[i];
			cost[a] = cost[b] = add/cnt + (i<rem) + 1;
		}
	}

	static ll dist[MAX_N];
	static bool used[MAX_N];

	rep(i,0,n) used[i]=0,dist[i]=inf;
	priority_queue< pair<ll,int> > pque;
	dist[s] = 0;
	pque.push(make_pair(-dist[s],s));

	while(!pque.empty()){
		int u = pque.top().second;
		pque.pop();
		if(u==t)
			return dist[t];
		if(used[u])
			continue;
		used[u]=1;
		for(auto e:edge[u])
			if(dist[u] + cost[e] < dist[to[e]]){
				dist[to[e]] = dist[u] + cost[e];
				pque.push(make_pair(-dist[to[e]],to[e]));
			}
	}

	return dist[t];
}

int main(){
	cin>>n>>m>>L>>s>>t;

	int nE=0;
	rep(it,0,m){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(nE);
		to[nE]=v;
		cost[nE]=w;
		if(w==0)
			erased_a.push_back(nE);

		nE++;
		edge[v].push_back(nE);
		to[nE]=u;
		cost[nE]=w;
		if(w==0)
			erased_b.push_back(nE);
		nE++;
	}

	ll l=-1,r=inf; //(l,r]
	if(check(0)>L||check(r)<L){
		puts("NO");
		return 0;
	}

	while(l+1<r){
		ll m = (l+r)>>1;
		if(check(m)>=L)
			r=m;
		else
			l=m;
	}

	puts("YES");

	if(!erased_a.empty()){
		ll add = r;
		int cnt = erased_a.size();
		int rem = add % cnt;
		rep(i,0,cnt){
			int a = erased_a[i], b = erased_b[i];
			cost[a] = cost[b] = add/cnt + (i<rem) + 1;
		}
	}

	for(int i=0;i<nE;i+=2){
		int a = i, b = i + 1;
		cout<<to[b]<<" "<<to[a]<<" "<<cost[a]<<endl;
	}

	return 0;
}