#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, t;
	cin >> n >> m >> t;
	
	vector <string> g(n);
	for(int i = 0; i < n; i++)
		cin >> g[i];
		
	vector < vector <int> > dist(n, vector <int> (m, -1));
	queue < pair <int, int> > q;
	
	const int di[] = {1, -1, 0, 0};
	const int dj[] = {0, 0, 1, -1};
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		bool found = false;
		for(int d = 0; d < 4; d++){
			int ni = i + di[d], nj = j + dj[d];
			if(ni < 0 || ni >= n || nj < 0 || nj >= m)continue;
			
			if(g[i][j] == g[ni][nj]){
				found = true;
				break;
			}
		}
		
		if(found){
			dist[i][j] = 0;
			q.push({i, j});
		}
	}
	
	while(!q.empty()){
		auto[i, j] = q.front();
		q.pop();
		
		for(int d = 0; d < 4; d++){
			int ni = i + di[d], nj = j + dj[d];
			if(ni < 0 || ni >= n || nj < 0 || nj >= m)continue;
			
			if(dist[ni][nj] == -1){
				dist[ni][nj] = dist[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}
	
	while(t--){
		int i, j;
		long long p;
		cin >> i >> j >> p;
		i--, j--;
		
		if(dist[i][j] == -1 || dist[i][j] >= p){
			cout << g[i][j] << '\n';
			continue;
		}
		
		if((p - dist[i][j]) % 2 == 0){
			cout << g[i][j] << '\n';
		}else{
			cout << (char)(g[i][j] ^ '0' ^ '1') << '\n';
		}
	}
	return 0;
}