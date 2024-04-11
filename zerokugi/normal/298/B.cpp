#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

#define REP(i, n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int t, sx, sy, ex, ey;
string s;
string ds="ESWN";
int dir[4][2] = {{1, 0},{0, -1},{-1, 0},{0, 1}};
ll dist(int sx, int sy, int dx, int dy){
	return abs(sx-dx)+abs(sy-dy);
}
main(){
	cin >> t >> sx >> sy >> ex >> ey >> s;
	int ans = 0;
	REP(i, s.size()){
		int cur = dist(sx, sy, ex, ey);
		if(cur == 0) break;
		REP(k, 4) if(s[i] == ds[k]){
			int tx = sx + dir[k][0];
			int ty = sy + dir[k][1];
			if(dist(tx, ty, ex, ey) < cur){
				sx = tx; sy = ty;
				break;
			}
		}
		ans ++;
	}
	if(dist(sx, sy, ex, ey) == 0) cout << ans << endl;
	else cout << -1 << endl;
}