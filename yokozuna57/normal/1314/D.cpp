#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

const int INF = 1000000000;

int n,k;
int w[82][82];

P cost[82][82][82];
void init_cost(){
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			int cnt = 0;
			for(int k = 0 ; k < n ; k ++){
				if(k == i || k == j)continue;
				cost[i][j][cnt++] = P(w[i][k]+w[k][j],k);
			}
			sort(cost[i][j],cost[i][j]+cnt);
		}
	}
}

int x[5];
int ret = INF;
bool used[82];
int c[5][5];
int dp[6][5];
void dfs(int t){
	for(int i = 0 ; i < t ; ++i){
		for(int j = 0 ; j < t ; ++j){
			for(int s = 0 ; ; ++s){
				if(!used[cost[x[i]][x[j]][s].sc]){
					c[i][j] = cost[x[i]][x[j]][s].fr;
					break;
				}
			}
		}
	}
	for(int i = 0 ; i <= k/2 ; ++i){
		for(int j = 0 ; j < t ; ++j){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i = 0 ; i < k/2 ; ++i){
		for(int j = 0 ; j < t ; ++j){
			for(int nex = 0 ; nex < t ; ++nex){
				if(dp[i+1][nex] > dp[i][j]+c[j][nex]){
					dp[i+1][nex] = dp[i][j]+c[j][nex];
				}
			}
		}
	}
	ret = min( ret , dp[k/2][0] );
	if(t == k/2 || t+1 == n)return;
	for(int i = x[t-1]+1 ; i < n ; i ++){
		x[t] = i;
		used[i] = true;
		dfs(t+1);
		used[i] = false;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			scanf("%d",&w[i][j]);
		}
	}
	init_cost();
	x[0] = 0;
	for(int i = 0 ; i < 82 ; i ++){
		used[i] = false;
	}
	used[0] = true;
	dfs(1);
	cout << ret << endl;
}