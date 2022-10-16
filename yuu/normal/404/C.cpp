#include <bits/stdc++.h>
using namespace std;
deque <pair <int, int>> layer[100001];
vector <pair <int, int>> edges;
int d[100001];
vector <int> v;
int n, k;
int root;
int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>d[i];
	for(int i=1; i<=n; i++){
		if(d[i]==0) root=i;
		else v.push_back(i);
	}
	if(v.size()+1!=n){
		cout<<"-1\n";
		return 0;
	}
	layer[0].push_back(make_pair(0, root));
	sort(v.begin(), v.end(), [](int a, int b){
		return d[a]<d[b];
	});
	for(int i: v){
		if(layer[d[i]-1].empty()){
			cout<<"-1\n";
			return 0;
		}
		auto x=layer[d[i]-1].front();
		layer[d[i]-1].pop_front();
		x.first++;
		if(x.first>k){
			cout<<"-1\n";
			return 0;
		}
		layer[d[i]-1].push_back(x);
		edges.push_back({x.second, i});
		layer[d[i]].push_back({1, i});
	}
	cout<<edges.size()<<'\n';
	for(auto &x: edges) cout<<x.first<<' '<<x.second<<'\n';
}