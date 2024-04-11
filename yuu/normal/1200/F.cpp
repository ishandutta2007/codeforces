#include <bits/stdc++.h>
using namespace std;
const int reimu=8*9*5*7;
int n;
vector <int> g[1001];
int k[1001];
vector <pair <int, int>> s;
int f[1001][reimu];
bool on[1001][reimu];
bool done[1001][reimu];
int last[1001];
int cnt=0;
int F(int u, int md){
	// cerr<<u<<' '<<md<<'\n';
	if(done[u][md]){
		if(on[u][md]){
			cnt++;
			f[u][md]=0;
			for(int i=s.size()-1; i>=0; i--){
				if(last[s[i].first]!=cnt){
					last[s[i].first]=cnt;
					f[u][md]++;
				}
				if((s[i].first==u)&&(s[i].second==md)) break;
			}
		}
		on[u][md]=0;
		return f[u][md];
	}
	else{
		done[u][md]=1;
		on[u][md]=1;
		s.push_back({u, md});
		f[u][md]=F(g[u][md%g[u].size()], (md+k[g[u][md%g[u].size()]])%reimu);
		s.pop_back();
		on[u][md]=0;
		return f[u][md];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>k[i];
		k[i]%=reimu;
		if(k[i]<0) k[i]+=reimu;
	}
	for(int i=1; i<=n; i++){
		int m;
		cin>>m;
		g[i].resize(m);
		for(auto &x: g[i]) cin>>x;
	}
	int q, x, y;
	cin>>q;
	while(q--){
		cin>>x>>y;
		y+=k[x];
		y%=reimu;
		if(y<0) y+=reimu;
		cout<<F(x, y)<<'\n';
	}
}