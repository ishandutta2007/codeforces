#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, f;
map <pair <string, string>, int> cost;
vector <int> s;
int main(){
	cin>>n>>a>>b>>k>>f;
	string old="";
	for(int i=1; i<=n; i++){
		string x, y;
		cin>>x>>y;
		auto key=make_pair(x, y);
		if(key.first>key.second) swap(key.first, key.second);
		if(x==old) cost[key]+=b;
		else cost[key]+=a;
		old=y;
	}
	for(auto x: cost) s.push_back(x.second);
	sort(s.begin(), s.end());
	int ans=0;
	while(!s.empty()){
		if(k==0) break;
		if(s.back()<=f) break;
		s.pop_back();
		ans+=f;
		k--;
	}
	for(auto &x: s) ans+=x;
	cout<<ans<<'\n';
}