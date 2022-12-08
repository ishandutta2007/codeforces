#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> tab(n);
	forn(i, n) cin >> tab[i];
	string comms;
	cin >> comms;
	
	vector<int> dx = {-1, 0, 1, 0};
	vector<int> dy = {0, -1, 0, 1};
	
	vector<int> mapeo = {0, 1, 2, 3};
	
	int sx = 0, sy = 0;
	
	forn(i, n) forn(j, m) {
		if(tab[i][j] == 'S') {
			sx = i;
			sy = j;
		}
	}
	
	int ans = 0;
	do {
		int px = sx, py = sy;
		forn(i, comms.size()) {
			px += dx[mapeo[comms[i]-'0']];
			py += dy[mapeo[comms[i]-'0']];
			if(px < 0 || px >= n || py < 0 || py >= m || tab[px][py] == '#' || tab[px][py] == 'E') break;
		}
		if(px >=0 && px < n && py >= 0 && py < m && tab[px][py] == 'E') ans++;
	}while(next_permutation(mapeo.begin(), mapeo.end()));
	
	cout << ans << endl;
	return 0;
}