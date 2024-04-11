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

int n, m;
struct seg{
	int x, y, l;
};
main(){
	scanf("%d%d", &n, &m);
	vector<seg> h(n);
	vector<seg> w(m);
	map<int, vector<seg>> hm;
	map<int, vector<seg>> wm;
	REP(i, n){
		cin >> h[i].x >> h[i].y >> h[i].l;
	}
	REP(i, m) cin >> w[i].x >> w[i].y >> w[i].l;
	int ans = 0;
	REP(i, n)REP(j, m){
		int tx = h[i].x;
		int ty = w[j].y;
		int l = min(min(ty - h[i].y, h[i].y+h[i].l-ty), min(tx - w[j].x, w[j].x+w[j].l-tx));
		ans = max(ans, l);
	}
	cout << ans << endl;
	return 0;
}