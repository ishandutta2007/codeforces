#include <bits/stdc++.h>
using namespace std;
#define next miku
int k;
int n[16];
int a[16][5001];
pair <int, int> next[16][5001];
map <long long, pair <int, int>> pos;
long long s[16];
long long sum;
vector <pair <int, int>> f[1<<16];
bool done[16][5001];
vector <pair <int, int>> temp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>k;
	for(int i=1; i<=k; i++){
		cin>>n[i];
		for(int j=1; j<=n[i]; j++){
			cin>>a[i][j];
			pos[a[i][j]]={i, j};
		}
		for(int j=1; j<=n[i]; j++) s[i]+=a[i][j];
		sum+=s[i];
	}
	if(sum%k){
		cout<<"No\n";
		return 0;
	}
	sum/=k;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n[i]; j++){
			///s[i]-a[i][j]+req=sum
			long long req=sum-s[i]+a[i][j];
			auto res=pos.find(req);
			if(res==pos.end()) continue;
			next[i][j]=res->second;
		}
	}
	for(int i=1; i<=k; i++)	if(s[i]!=sum){
		for(int j=1; j<=n[i]; j++){
			temp.clear();
			temp.push_back({i, j});
			done[temp.back().first][temp.back().second]=1;
			while((temp.back().first!=0)&&(temp.size()<20)){
				temp.push_back(next[temp.back().first][temp.back().second]);
				if(done[temp.back().first][temp.back().second]) break;
				done[temp.back().first][temp.back().second]=1;
			}
			for(auto &x: temp) done[x.first][x.second]=0;
			if(temp.back().first==0) continue;
			if(temp.back().first!=i||temp.back().second!=j) continue;
			temp.pop_back();
			int mask=0;
			bool bad=0;
			for(auto x: temp){
				int id=x.first-1;
				if((mask>>id)&1){
					bad=1;
					break;
				}
				mask^=1<<id;
			}
			if(bad) continue;
			if(!f[mask].empty()) continue;
			f[mask]=temp;
		}
	}
	else{
		next[i][1]={i, 1};
		f[1<<(i-1)].push_back({i, 1});
	}
	for(int i=1; i<(1<<k); i++) if(f[i].empty()){
		for(int j=(i-1)&i; j>0; j=(j-1)&i){
			if(!f[j].empty()) if(!f[i^j].empty()){
				f[i]=f[i^j];
				for(auto x: f[j]) f[i].push_back(x);
				break;
			}
		}
	}
	// cerr<<"Ok\n";
	int ep=(1<<k)-1;
	if(f[ep].empty()){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	vector <pair <long long, int>> ans;
	ans.resize(k+1);
	for(auto &x: f[ep]){
		auto nx=next[x.first][x.second];
		ans[nx.first]={a[nx.first][nx.second], x.first};
	}
	for(int i=1; i<=k; i++) cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}