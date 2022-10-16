#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n, m, t;
int u[100001];
int v[100001];
int c[100001];
int y[100001];
vector <int> f[100001];
class cmp{
public:
	bool operator ()(pair <int, ll> A, pair <int, ll> B){
		return A.second>B.second;
	}
};
ll d[100001];
ll r[100001];
deque <int> q[100001];
void fix(){
	q[0].push_back(1);
	for(int i=1; i<=n; i++) r[i]=n+1;
	r[1]=0;
	for(int i=0; i<=n; i++){
		while(!q[i].empty()){
			int u=q[i].front();
			q[i].pop_front();
			if(r[u]!=i) continue;
			for(int &x: f[u]) if(r[v[x]]+d[v[x]]>r[u]+d[u]+c[x]){
				r[v[x]]=r[u]+d[u]+c[x]-d[v[x]];
				q[r[v[x]]].push_back(v[x]);
			}
		}
	}
	for(int i=1; i<=n; i++) if(d[i]!=-1) d[i]+=r[i];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>t;
	for(int i=1; i<=m; i++){
		cin>>u[i]>>v[i]>>c[i];
		f[u[i]].push_back(i);
	}
	for(int i=1; i<=n; i++) d[i]=1e18;
	d[1]=0;
	{
		priority_queue <pair <int, ll>, vector <pair <int, ll>>, cmp> q;
		q.push({1, 0});
		while(!q.empty()){
			auto p=q.top();
			q.pop();
			if(p.second>d[p.first])	continue;
			for(int i: f[p.first]) if(d[v[i]]>d[u[i]]+c[i]){
				d[v[i]]=d[u[i]]+c[i];
				q.push({v[i], d[v[i]]});
			}
		}
	}
	for(int i=1; i<=n; i++) if(d[i]==1e18) d[i]=-1;
	for(int i=1, s, v, x; i<=t; i++){
		cin>>s>>v;
		if(s==1) cout<<d[v]<<'\n';
		else{
			while(v--){
				cin>>x;
				c[x]++;
			}
			fix();
		}
	}
}