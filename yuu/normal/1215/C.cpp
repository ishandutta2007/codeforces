#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
int cnt[2];
vector <int> posa[2];
vector <int> posb[2];
int main(){
	cin>>n>>a>>b;
	for(char &c: a) c-='a';
	for(char &c: b) c-='a';
	for(char c: a) cnt[c]++;
	for(char c: b) cnt[c]++;
	if(cnt[1]%2){
		cout<<"-1\n";
		return 0;
	}
	for(int i=0; i<n; i++) if(a[i]!=b[i]){
		posa[a[i]].push_back(i);
		posb[b[i]].push_back(i);
	}
	vector <pair <int, int>> ans;
	while(posa[0].size()>=2){
		int x=posa[0].back();
		posa[0].pop_back();
		int y=posa[0].back();
		posa[0].pop_back();
		ans.push_back({x, y});
	}
	while(posa[1].size()>=2){
		int x=posa[1].back();
		posa[1].pop_back();
		int y=posa[1].back();
		posa[1].pop_back();
		ans.push_back({x, y});
	}
	if(!posa[0].empty()){
		int x=posa[0].back();
		posa[0].pop_back();
		int y=posa[1].back();
		posa[1].pop_back();
		ans.push_back({x, x});
		ans.push_back({x, y});
	}
	cout<<ans.size()<<'\n';
	for(auto &x: ans)	cout<<x.first+1<<' '<<x.second+1<<'\n';
}