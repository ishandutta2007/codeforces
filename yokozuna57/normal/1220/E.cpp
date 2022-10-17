#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef long double ld;
typedef long long ll;

int main(){
	static int n,m;
	static ll w[200010];
	static int a[200010],b[200010];
	static int s;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&w[i]);
	}
	for(int i = 0 ; i < m ; i ++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
	}
	scanf("%d",&s); s--;
	
	static vector<int> G[200010];
	for(int i = 0 ; i < m ; i ++){
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	
	static int d[200010] = {};
	static bool used[200010];
	for(int i = 0 ; i < m ; i ++){
		d[a[i]] ++;
		d[b[i]] ++;
	}
	static queue<int> que;
	for(int i = 0 ; i < n ; i ++){
		if(d[i] == 1)que.push(i);
		used[i] = false;
	}
	static ll dp[200010] = {};
	while(!que.empty()){
		int v = que.front(); que.pop();
		//cout << v << endl;
		if(v == s || used[v])continue;
		used[v] = true;
		for(int i = 0 ; i < G[v].size() ; i ++){
			if(!used[G[v][i]]){
				dp[G[v][i]] = max( dp[G[v][i]] , dp[v]+w[v] );
				d[G[v][i]] --;
				d[v] --;
				if(d[G[v][i]] == 1){
					que.push(G[v][i]);
				}
			}
		}
	}
	
	static ll ret = 0;
	static ll sum = 0;
	for(int i = 0 ; i < n ; i ++){
		if(!used[i]){
			sum += w[i];
			ret = max( ret , dp[i] );
		}
	}
	cout << ret+sum << endl;
}