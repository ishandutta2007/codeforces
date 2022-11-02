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
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;
int g[2001][1001];
int n;
main(){
	scanf("%d", &n);
	int x = 0, y = 1000;
	int miny = 1000;
	int maxy = 1000;
	REP(i, n){
		int t;
		scanf("%d", &t);
		REP(j, t){
			if(i%2){
				g[--y][x] = -1;
			}else{
				g[y++][x] = 1;
			}
			miny = min(miny, y);
			maxy = max(maxy, y);
			x ++;
		}
	}
	for(int i=maxy-1;i>=miny;i--){
		REP(j, x){
			putchar(g[i][j] ? (g[i][j]==1 ? '/' : '\\') : ' ');
		}
		puts("");
	}
	return 0;
}