#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[5][51];
vector <pair <int, pair <int, int>>> ans;
bool try_parking(){
	bool done=1;
	for(int i=1; i<=n; i++) if(f[2][i]){
		if(f[2][i]==f[1][i]){
			ans.push_back({f[2][i], {1, i}});
			f[2][i]=f[1][i]=0;
		}
		else done=0;
	}
	for(int i=1; i<=n; i++) if(f[3][i]){
		if(f[3][i]==f[4][i]){
			ans.push_back({f[3][i], {4, i}});
			f[3][i]=f[4][i]=0;
		}
		else done=0;
	}
	return done;
}
bool try_shifting(){
	int ex=-1;
	int ey=-1;
	for(int i=1; i<=n; i++) if(f[2][i]==0){
		ex=2;
		ey=i;
	}
	for(int i=1; i<=n; i++) if(f[3][i]==0){
		ex=3;
		ey=i;
	}
	if(ex==-1) return 0;
	vector <pair <int, int>> path;
	path.push_back({ex, ey});
	while(path.size()<n*2){
		path.push_back(path.back());
		if(path.back().first==3){
			path.back().second++;
			if(path.back().second>n){
				path.back().second=n;
				path.back().first=2;
			}
		}
		else{
			path.back().second--;
			if(path.back().second==0){
				path.back().second=1;
				path.back().first=3;
			}
		}
	}
	for(int i=1; i<path.size(); i++){
		if(f[path[i].first][path[i].second]){
			ans.push_back({f[path[i].first][path[i].second], path[i-1]});
			f[path[i-1].first][path[i-1].second]=f[path[i].first][path[i].second];
			f[path[i].first][path[i].second]=0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>k;
	for(int i=1; i<=4; i++)	for(int j=1; j<=n; j++) cin>>f[i][j];
	int cnt=0;
	while(!try_parking()){
		if(!try_shifting()){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto x: ans){
		cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<'\n';
	}
}