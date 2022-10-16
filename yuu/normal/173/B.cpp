#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[1001][1001];
const int cx[]={1, -1, 0, 0};
const int cy[]={0, 0, 1, -1};
int f[1001][1001][5];
deque <pair <pair <int, int>, int>> q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>c[i][j];
	for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) for(int k=0; k<5; k++) f[i][j][k]=1e9;
	f[n][m][3]=0;
	q.push_back(make_pair(make_pair(n, m), 3)); 
	while(!q.empty()){
		auto p=q.front();
		q.pop_front();
		if(p.second==4){
			for(int i=0; i<4; i++){
				auto nx=p;
				nx.first.first+=cx[i];
				nx.first.second+=cy[i];
				nx.second=i;
				if(nx.first.first>n||nx.first.first<0) continue;
				if(nx.first.second>m||nx.first.second<0) continue;
				if(f[nx.first.first][nx.first.second][nx.second]>f[p.first.first][p.first.second][p.second]){
					f[nx.first.first][nx.first.second][nx.second]=f[p.first.first][p.first.second][p.second];
					q.push_front(nx);
				}
			}
		}
		else{
			for(int i=0; i<1; i++){
				auto nx=p;
				nx.first.first+=cx[p.second];
				nx.first.second+=cy[p.second];
				if(nx.first.first>n||nx.first.first<0) continue;
				if(nx.first.second>m||nx.first.second<0) continue;
				if(f[nx.first.first][nx.first.second][nx.second]>f[p.first.first][p.first.second][p.second]){
					f[nx.first.first][nx.first.second][nx.second]=f[p.first.first][p.first.second][p.second];
					q.push_front(nx);
				}
			}
			if(c[p.first.first][p.first.second]=='#'){
				auto nx=p;
				nx.second=4;
				if(f[nx.first.first][nx.first.second][nx.second]>f[p.first.first][p.first.second][p.second]+1){
					f[nx.first.first][nx.first.second][nx.second]=f[p.first.first][p.first.second][p.second]+1;
					q.push_back(nx);
				}
			}
		}
	}
	if(f[1][0][3]==1e9) f[1][0][3]=-1;
	cout<<f[1][0][3]<<'\n';
}