#include<bits/stdc++.h>
using namespace std;

const int maxn = 3010;
bool vis[maxn];
int to[maxn];

void dfs(int x){
	vis[x] = true;
	if(!vis[to[x]])
		dfs(to[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> to[i];
	int m, cyc = 0;
	cin >> m;
	m = n - m;
	for(int i=1;i<=n;i++)
		if(!vis[i]) {
			dfs(i);
			cyc++;
		}
	cout << abs(cyc - m) << endl;
	if(cyc > m) {
		memset(vis,0,sizeof vis);
		dfs(1);
		for(int i=1,j=0;j<cyc-m;i++)
			if(!vis[i]){
				cout << 1 << ' ' << i << ' ';
				dfs(i);
				j++;
			}
		cout << endl;
	}
	else if(cyc < m) {
		int k = m - cyc;
		while(k--){
			for(int i=1;i<=n;i++)
				if(i != to[i]){
					int j = maxn, x = i;
					while(to[x] != i){
						x = to[x];
						j = min(x, j);
					}
					cout << i << ' ' << j << ' ';
					swap(to[i], to[j]);
					break;
				}
		}
	}
}