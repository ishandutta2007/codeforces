#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, ui, vi;
char ci;
vector < pair <int, char> > G[MAXN];

int dp[MAXN][MAXN][30];
bool win(int i, int j, int c){
	if(dp[i][j][c] != -1)return dp[i][j][c];
	
	bool r = false;
	for(pair <int, char> e : G[i]){
		if(e.second - 'a' < c)continue;
		if(!win(j, e.first, e.second - 'a'))r = true;
	}
	return (dp[i][j][c] = r);
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %c", &ui, &vi, &ci);
		ui--, vi--;
		
		G[ui].push_back(make_pair(vi, ci));
	}
	
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(win(i, j, 0))printf("A");
			else printf("B");
		}
		printf("\n");
	}
	
	return 0;
}