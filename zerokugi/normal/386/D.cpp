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
const int INF = 100000000;
class DP{
public:
	int cost;
	int stones[3];
	vector<pii> logs;
	
	DP(){}
	DP(int cc){
		cost = cc;
	}
	
	bool operator< (const DP &opp) const {
		return cost>opp.cost;
	}
};

int memo[71][71][71];
char g[80][80];
main(){
	int n;
	cin >> n;
	DP S;
	S.cost = 0;
	REP(i, 3) cin >> S.stones[i];
	REP(i, n) cin >> &g[i+1][1];
	sort(S.stones, S.stones+3);
	REP(i, 71)REP(j, 71)REP(k, 71) memo[i][j][k] = INF;
	priority_queue<DP> dp;
	dp.push(S);
	while(!dp.empty()){
		S = dp.top();
		dp.pop();
//		printf("%d: %d %d %d\n", S.cost, S.stones[0], S.stones[1], S.stones[2]);
		if(S.stones[2] == 3) break;
		for(int i=0;i<3;i++){
			int s = S.stones[0];
			int t = S.stones[1];
			int v = S.stones[2];
			if(i == 0) swap(v, s);
			if(i == 1) swap(v, t);
			for(int j=1;j<=n;j++){
				if(v!=j && s!=j && t!=j && g[s][t] == g[v][j]){
					DP T = S;
					T.logs.push_back(pii(v, j));
					T.cost ++;
					T.stones[0] = s;
					T.stones[1] = t;
					T.stones[2] = j;
					sort(T.stones, T.stones+3);
					if(memo[T.stones[0]][T.stones[1]][T.stones[2]] > T.cost){
						memo[T.stones[0]][T.stones[1]][T.stones[2]] = T.cost;
						dp.push(T);
					}
				}
			}
		}
	}
	if(S.stones[2] == 3){
		cout << S.logs.size() << endl;
		FOR(it, S.logs) cout << it->first << " " << it->second << endl;
	}else{
		cout << "-1" << endl;
	}
	return 0;
}