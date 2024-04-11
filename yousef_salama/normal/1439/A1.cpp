#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector <string> g(n);
		for(int i = 0; i < n; i++)
			cin >> g[i];
		
		auto flip = [&](int i, int j){
						if(g[i][j] == '0')g[i][j] = '1';
						else g[i][j] = '0';
					};
		
		vector < array <int, 6> > v;
		for(int i = 0; i + 2 < n; i++){
			for(int j = 0; j < m; j++){
				if(g[i][j] == '1'){
					if(j == m - 1){
						v.push_back({i, j, i + 1, j, i + 1, j - 1});
						flip(i + 1, j);
						flip(i + 1, j - 1);
						flip(i, j);
					}else{
						v.push_back({i, j, i + 1, j, i + 1, j + 1});
						flip(i + 1, j);
						flip(i + 1, j + 1);
						flip(i, j);
					}
				}
			}
		}
		
		for(int j = 0; j + 2 < m; j++){
			if(g[n - 2][j] == '1'){
				v.push_back({n - 2, j, n - 2, j + 1, n - 1, j + 1});
				flip(n - 2, j);
				flip(n - 2, j + 1);
				flip(n - 1, j + 1);
			}
			if(g[n - 1][j] == '1'){
				v.push_back({n - 1, j, n - 2, j + 1, n - 1, j + 1});
				flip(n - 1, j);
				flip(n - 2, j + 1);
				flip(n - 1, j + 1);
			}
		}
		
		vector < vector <int> > r(2, vector <int> (2, 0));
		if(g[n - 2][m - 2] == '1'){
			r[0][1] ^= 1;
			r[1][0] ^= 1;
			r[1][1] ^= 1;
		}
		if(g[n - 2][m - 1] == '1'){
			r[0][0] ^= 1;
			r[1][0] ^= 1;
			r[1][1] ^= 1;
		}
		if(g[n - 1][m - 2] == '1'){
			r[0][0] ^= 1;
			r[0][1] ^= 1;
			r[1][1] ^= 1;
		}
		if(g[n - 1][m - 1] == '1'){
			r[0][0] ^= 1;
			r[0][1] ^= 1;
			r[1][0] ^= 1;
		}
		
		if(r[0][0])v.push_back({n - 2, m - 1, n - 1, m - 2, n - 1, m - 1});
		if(r[0][1])v.push_back({n - 2, m - 2, n - 1, m - 2, n - 1, m - 1});
		if(r[1][0])v.push_back({n - 2, m - 2, n - 2, m - 1, n - 1, m - 1});
		if(r[1][1])v.push_back({n - 2, m - 2, n - 2, m - 1, n - 1, m - 2});
		
		cout << v.size() << '\n';
		for(auto z : v)
			cout << z[0] + 1 << ' ' << z[1] + 1 << ' ' << z[2] + 1 << ' ' << z[3] + 1 << ' ' << z[4] + 1 << ' ' << z[5] + 1 << '\n';
	}
	return 0;
}