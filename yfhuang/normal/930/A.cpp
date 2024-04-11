#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> G[maxn];

int n;
int p[maxn];
int dep[maxn];

void dfs(int u,int d){
	dep[u] = d;
	for(auto v: G[u]){
		dfs(v,d + 1);
	}
}
int num[maxn];
int main(){
	while(cin >> n){
		for(int i = 1;i <= n;i++){
			G[i].clear();
			num[i] = 0;
		}
		for(int i = 1;i < n;i++){
			int par;
			scanf("%d",&par);
			G[par].push_back(i + 1);
		}
		dfs(1,1);
		for(int i = 1;i <= n;i++)
			num[dep[i]]++;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans += num[i] & 1;
		}
		cout << ans << endl;
	}
	return 0;
}