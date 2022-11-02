#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

typedef pair<int, int> pii;
int n,m;
struct edge{
	int to, l, r;
};
vector<edge> g[1001];

class DP{
public:
	int cost, n;
	
	DP(){}
	DP(int nn, int cc){
		cost = cc;n=nn;
	}
	
	bool operator< (const DP &opp) const {
		return cost>opp.cost;
	}
};
int visit[1001];

int check(int r){
	REP(i, n) visit[i] = 10000000;
	priority_queue<DP> dp;
	DP S;
	dp.push(DP(0, 0));
	while(!dp.empty()){
		S = dp.top();
		dp.pop();
//		printf("pop %d %d\n", S.n, S.cost);
		if(S.n == n-1) break;
		FOR(e, g[S.n]){
			if(e->r < r || r < e->l) continue;
			DP T=S;
			T.n = e->to;
			T.cost = max(T.cost, e->l);
			if(visit[T.n] <= T.cost) continue;
			visit[T.n] = T.cost;
			dp.push(T);
		}
	}
	return S.n == n-1 ? r - S.cost + 1 : 0;
}

main(){
	cin >> n >> m;
	set<int> dic;
	REP(i, m){
		int a,b,l,r;
		cin >>a>>b>>l>>r;
		g[a-1].push_back((edge){b-1, l, r});
		g[b-1].push_back((edge){a-1, l, r});
//		dic.insert(l);
		dic.insert(r);
	}
	int ans = 0;
	FOR(it, dic){
		int ret = check(*it);
		ans = max(ans, ret);
//		printf("check(%d) = %d\n", *it, ret);
	}
	if(ans) cout << ans << endl;
	else cout << "Nice work, Dima!" << endl;
	return 0;
}