#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
vector <int> g[200001];
int val[100001];
int cnt;
bool done[200001];
bool on[200001];
deque <int> orders;
bool dfs(int u){
	done[u]=1;
	on[u]=1;
	for(int v: g[u]) if(!done[v]){
		if(dfs(v)) return 1;
	}
	else if(on[v]) return 1;
	orders.push_front(u);
	on[u]=0;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cnt=m;
	for(int i=1; i<=n; i++){
		vector <int> pos;
		for(int j=1; j<=m; j++){
			cin>>a[j];
			if(a[j]!=-1) pos.push_back(j);
		}
		sort(pos.begin(), pos.end(), [](int u, int v){
			return a[u]<a[v];
		});
		for(int j=0; j<pos.size(); j++){
			int k=j+1;
			while((k<pos.size())&&(a[pos[k]]==a[pos[j]])) k++;
			cnt++;
			for(int l=j; l<k; l++){
				g[cnt].push_back(pos[l]);
				val[l]=cnt;
			}
			j=k-1;
		}
		for(int j=0; j<pos.size(); j++){
			int k=j+1;
			while((k<pos.size())&&(a[pos[k]]==a[pos[j]])) k++;
			if(k==pos.size()) break;
			for(int l=j; l<k; l++) g[pos[l]].push_back(val[k]);
			j=k-1;
		}
	}
	for(int i=1; i<=cnt; i++) if(!done[i]) if(dfs(i)){
		cout<<"-1\n";
		return 0;
	}
	for(auto &x: orders) if(x<=m) cout<<x<<' ';
	cout<<'\n';
}