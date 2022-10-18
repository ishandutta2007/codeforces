#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

int n, m, q, y;

string s[MAXN], t[MAXN], r[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < m; i++)
		cin >> t[i];
		
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		r[i][j] = s[i] + t[j];
		
	cin >> q;
	while(q--){
		cin >> y;
		y--;
		
		cout << r[y % n][y % m] << endl;
	}
	return 0;
}