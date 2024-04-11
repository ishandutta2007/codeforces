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
vector<int> Edge[100005];
int par[100005];
int val[100005];
void setpar(int r){
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		r = q.front();
		q.pop();
		FOR(i, Edge[r]){
			if(par[r] != *i){
				par[*i] = r;
				q.push(*i);
			}
		}
	}
}

main(){
	scanf("%d", &n);
	REP(i,n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		Edge[u-1].push_back(v-1);
		Edge[v-1].push_back(u-1);
	}
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n){
		int x;
		scanf("%d", &x);
		val[i] ^= x;
	}
	
	REP(i, n+1) par[i] = n;
	
	setpar(0);
	vector<int> ans;
	REP(i, n){
		if(val[par[par[i]]] ^ val[i]) ans.push_back(i+1);
	}
	printf("%d\n", (int)ans.size());
	REP(i, ans.size()) printf("%d\n", ans[i]);
	return 0;
}