#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n;
int g[2005][2005];

int visited[2005];

void dfs(int s){
	REP(i, n){
		if(g[s][i] && !visited[i]){
			visited[i] = 1;
			dfs(i);
		}
	}
}

void rdfs(int s){
	REP(i, n){
		if(g[i][s] && !visited[i]){
			visited[i] = 1;
			rdfs(i);
		}
	}
}

main(){
	scanf("%d", &n);
	REP(i, n)REP(j, n){
		int t;
		scanf("%d", &t);
		g[i][j] = !!t;
	}
	
	REP(i, n) visited[i] = 0;
	dfs(0);
	REP(i, n) if(visited[i] == 0){
		puts("NO");
		return 0;
	}
	
	REP(i, n) visited[i] = 0;
	rdfs(0);
	REP(i, n) if(visited[i] == 0){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	return 0;
}