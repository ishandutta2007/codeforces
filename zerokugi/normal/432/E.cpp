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
#define rep(i,x) for(int i=1;i<=(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int w, h;
char m[105][105];
char tryFill(int sx, int sy, int l){
	if(sx+l-1>w || sy+l-1>h) return -1;
	vector<int> f(256);
	REP(i, l){
		REP(j, l){
			if(m[sy+i][sx+j]) return -1;
		}
		f[m[sy+i][sx-1]] = 1;
		f[m[sy+i][sx+l]] = 1;
		f[m[sy-1][sx+i]] = 1;
		f[m[sy+l][sx+i]] = 1;
	}
	for(char c='A';c<='Z';c++) if(!f[c]) return c;
	return 0;
}
void fill(){
	rep(i, h)rep(j, w){
		if(m[i][j]) continue;
		char t = tryFill(j, i, 1);
		int l=1;
		for(int k=2;;k++){
			if(tryFill(j+k-1, i, 1) < t || tryFill(j, i, k) != t) break;
			l=k;
		}
		REP(k, l)REP(x, l){m[i+k][j+x] = t;
//		printf("%c %d ,m[%d][%d]=%c;\n", t, l, i+l, j+x, m[i+l][j+x]);
		}
	}
}

main(){
	scanf("%d%d", &h, &w);
	fill();
	REP(i, h) printf("%s\n", &m[i+1][1]);
	return 0;
}