#include <bits/stdc++.h>
using namespace std;
int y[50001];
int z[50001];
map <int, vector <int>> m;
map <int, vector <int>> s;
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1, x; i<=n; i++){
		cin>>x>>y[i]>>z[i];
		m[x].push_back(i);
	}
	vector <int> overx;
	for(auto x: m){
		s.clear();
		for(auto i: x.second)	s[y[i]].push_back(i);
		vector <int> overy;
		for(auto &y: s){
			sort(y.second.begin(), y.second.end(), [](int a, int b){
				return z[a]<z[b];
			});
			while(y.second.size()>=2){
				cout<<y.second.back()<<' ';
				y.second.pop_back();
				cout<<y.second.back()<<'\n';
				y.second.pop_back();
			}
			if(!y.second.empty()) overy.push_back(y.second.back());
		}
		while(overy.size()>=2){
			cout<<overy.back()<<' ';
			overy.pop_back();
			cout<<overy.back()<<'\n';
			overy.pop_back();
		}
		if(!overy.empty()) overx.push_back(overy.back());
	}
	while(overx.size()>=2){
		cout<<overx.back()<<' ';
		overx.pop_back();
		cout<<overx.back()<<'\n';
		overx.pop_back();
	}
}