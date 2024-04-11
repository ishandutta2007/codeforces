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
#include <cmath>
#include <ctime>
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


main(){
	int g[5][5];
	REP(i, 5)REP(j, 5) cin >> g[i][j];
//	REP(i, 5)REP(j, 5) g[i][j] += g[j][i];
	int m[5]={0, 1, 2, 3, 4};
	int ans = 0;
	do{
		ans = max(ans, g[m[0]][m[1]]+g[m[1]][m[2]]+g[m[2]][m[3]]*2+g[m[3]][m[4]]*2
					  +g[m[1]][m[0]]+g[m[2]][m[1]]+g[m[3]][m[2]]*2+g[m[4]][m[3]]*2);
	}while(next_permutation(m, m+5));
	cout << ans << endl;
	return 0;
}