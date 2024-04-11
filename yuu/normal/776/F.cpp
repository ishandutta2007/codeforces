#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector <int> c[100002];
vector <int> g[100002];
map <pair <int, int>, int> edges;
int t;
bool out[100002];
int done[100002];
int ans[100002];
int sz[100002];
void dfs(int u){
	done[u]=t;
	sz[u]=1;
	for(int v: g[u]) if(!out[v]) if(done[v]!=t){
		dfs(v);
		sz[u]+=sz[v];
	}
}
void centroid(int u, int c){
	t++;
	dfs(u);
	int total=sz[u];
	bool good=1;
	while(good){
		good=0;
		for(int v: g[u]) if(!out[v]) if(sz[v]<sz[u]) if(sz[v]*2>=total){
			u=v;
			good=1;
			break;
		}
	}
	ans[u]=c;
	out[u]=1;
	for(int v: g[u]) if(!out[v]) centroid(v, c+1);
}
class element{
public:
	using pointer=element*;
	int value;
	pointer next, prev;
	element(int x=0){
		value=x;
		next=prev=nullptr;
	}
};
element::pointer pt[100002];
vector <pair <int, int>> split;
int cost(pair <int, int> a){
	int res=a.second-a.first;
	if(res<0) res+=n;
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++)	pt[i]=new element(i);
	for(int i=1; i<=n; i++)	pt[i]->next=pt[i%n+1];
	for(int i=1; i<=n; i++)	pt[i%n+1]->prev=pt[i];
	for(int i=1, a, b; i<=m; i++){
		cin>>a>>b;
		if(a>b) swap(a, b);
		if(2*(b-a)>n) swap(a, b);
		split.push_back({a, b});			
	}
	sort(split.begin(), split.end(), [](pair <int, int> A, pair <int, int> B){
		return cost(A)<cost(B);
	});
	int pos=1;
	for(auto a: split){
		auto now=pt[a.first]->next;
		pos=a.first;
		k++;
		while(now!=pt[a.second]){
			c[k].push_back(now->value);
			now=now->next;
		}
		c[k].push_back(pt[a.first]->value);
		c[k].push_back(pt[a.second]->value);
		sort(c[k].begin(), c[k].end());
		reverse(c[k].begin(), c[k].end());
		pt[a.first]->next=pt[a.second];
		pt[a.second]->prev=pt[a.first];
		pos=a.first;
	}
	k++;
	auto now=pt[pos];
	do{
		c[k].push_back(now->value);
		now=now->next;
	}
	while(now!=pt[pos]);
	sort(c[k].begin(), c[k].end());
	reverse(c[k].begin(), c[k].end());
	sort(c+1, c+k+1);
	for(int i=1; i<=k; i++){
		for(int j=0; j<c[i].size(); j++){
			pair <int, int> p={c[i][j], c[i][(j+1)%c[i].size()]};
			if(p.first>p.second) swap(p.first, p.second);
			if(edges[p]){
				g[i].push_back(edges[p]);
				g[edges[p]].push_back(i);
			}
			else edges[p]=i;
		}
	}
	centroid(1, 1);
	for(int i=1; i<=k; i++) cout<<ans[i]<<" \n"[i==k];
}