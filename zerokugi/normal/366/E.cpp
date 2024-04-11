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
int n,m,k,s;

int maxx[2000][10];
int minx[2000][10];
int g[10][10];
main(){
	cin >> n >> m >> k >> s;
	set<int> dic;
	REP(i, n)REP(j, k) maxx[i][j] = -1;
	REP(i, n)REP(j, k) minx[i][j] = 3000;
	REP(i, k)REP(j, k) g[i][j] = 0;
	REP(i, n)REP(j, m){
		int a;
		cin >> a;
		maxx[i][a-1] = max(maxx[i][a-1], j);
		minx[i][a-1] = min(minx[i][a-1], j);
	}
	REP(a, k)REP(b, k){
		if(b < a) continue;
		REP(i, n){
			if(maxx[i][a] < 0) continue;
			REP(j, n){
				if(maxx[j][b] < 0) continue;
				g[a][b] = g[b][a] = max(g[a][b], max(maxx[i][a] - minx[j][b] + abs(i-j), maxx[j][b] - minx[i][a] + abs(i-j)));
			}
		}
	}
	int prev, t;
	int ans = 0;
	cin >> prev;
	REP(i, s-1){
		cin >> t;
		ans = max(ans, g[prev-1][t-1]);
		prev = t;
	}
	cout << ans << endl;
	return 0;
}