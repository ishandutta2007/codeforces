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

tint visit(int i, vector<vector<tint>>& grafo, vector<tint>& visited, vector<tint>& c) {
	visited[i] = 1;
	tint ans = c[i];
	forn(j, grafo[i].size()) {
		int n = grafo[i][j];
		if(!visited[n]) {
			ans = min(ans,visit(n, grafo, visited, c));
		}
	}
	return ans;
}

int main()
{
	tint n,m;
	cin >> n >> m;
	vector<tint> c(n);
	forn(i,n) cin >> c[i];
	vector<vector<tint>> grafo(n);
	forn(i,m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	vector<tint> visited(n,0);
	tint ans = 0;
	forn(i,n) {
		if(!visited[i]) {
			ans += visit(i, grafo, visited, c);
		}
	}
	cout << ans << endl;
    return 0;
}