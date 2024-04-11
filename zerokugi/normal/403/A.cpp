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

int n,p,T;
int g[30][30];
main(){
	scanf("%d", &T);
	REP(t, T){
		scanf("%d%d", &n, &p);
		vector<pii> edges;
		vector<int> lev(n, 0);
		REP(i, 30)REP(j, 30)g[i][j] = i==j;
		REP(k, 2*n+p){
			int minu=0;
			REP(i, n) if(lev[minu] > lev[i]) minu = i;
			int minv=-1;
			REP(i, n) if(!g[minu][i] && (minv==-1 || lev[minv] > lev[i])) minv = i;
			edges.push_back(pii(minu, minv));
			g[minu][minv] = g[minv][minu] = 1;
			lev[minu]++;
			lev[minv]++;
		}
		FOR(it, edges) printf("%d %d\n", it->first+1, it->second+1);
	}
	return 0;
}