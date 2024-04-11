#include <bits/stdc++.h>
using namespace std;
int n;
int h[300001];
vector <int> a, b;
int f[300001];
vector <int> g[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>h[i];
	a.push_back(1);
	for(int i=2; i<=n; i++){
		while((!a.empty())&&(h[a.back()]<h[i])) a.pop_back();
		if(!a.empty()) g[i].push_back(a.back());
		a.push_back(i);
	}
	a.clear();
	a.push_back(1);
	for(int i=2; i<=n; i++){
		while((!a.empty())&&(h[a.back()]>h[i])) a.pop_back();
		if(!a.empty()) g[i].push_back(a.back());
		a.push_back(i);
	}
	a.clear();
	a.push_back(n);
	for(int i=n-1; i>=1; i--){
		while((!a.empty())&&(h[a.back()]<h[i])) a.pop_back();
		if(!a.empty()) g[a.back()].push_back(i);
		a.push_back(i);
	}
	a.clear();
	a.push_back(n);
	for(int i=n-1; i>=1; i--){
		while((!a.empty())&&(h[a.back()]>h[i])) a.pop_back();
		if(!a.empty()) g[a.back()].push_back(i);
		a.push_back(i);
	}
	a.clear();
	for(int i=2; i<=n; i++){
		f[i]=f[i-1]+1;
		for(int j: g[i]){
			// cerr<<i<<' '<<j<<'\n';
			f[i]=min(f[i], f[j]+1);
		}
	}
	cout<<f[n]<<'\n';
}