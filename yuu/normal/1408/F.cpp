#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n;
vector <int> f[15001];
set <pair <int, int>> s;
vector <pair <int, int>> ans;
pair <int, int> merge(int a, int b){
	for(int i=0; i<f[a].size(); i++){
		ans.push_back({f[a][i], f[b][i]});
		f[b].push_back(f[a][i]);
	}
	f[a].clear();
	return {f[b].size(), b};
}
deque <int> q;
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++){
		f[i].push_back(i);
		s.insert({1, i});
	}
	while(s.size()>=2){
		auto a=*s.begin();
		s.erase(s.begin());
		auto b=*s.begin();
		s.erase(s.begin());
		if(a.first==b.first){
			auto res=merge(a.second, b.second);
			s.insert(res);
		}
		else{
			q.push_back(a.second);
			s.insert(b);
		}
	}
	if(!s.empty()) q.push_back(s.begin()->second);
	while(q.size()>2){
		while(f[q[0]].size()<f[q[1]].size()){
			int sz=f[q[0]].size();
			for(int i=0; i<sz; i++){
				ans.push_back({f[q[0]][i], f[q.back()].back()});
				f[q[0]].push_back(f[q.back()].back());
				f[q.back()].pop_back();
			}
		}
		int a=q.front();
		q.pop_front();
		merge(a, q.front());
	}
	cout<<ans.size()<<'\n';
	for(auto p: ans) cout<<p.first<<' '<<p.second<<'\n';
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}