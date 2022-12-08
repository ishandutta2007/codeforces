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
using namespace std;
typedef long long tint;
typedef pair<tint, tint> pii;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;

void paint(int act, vvi& grafo, vi& color, int actc) {
	color[act] = actc;
	forn(i, grafo[act].size()) {
		int vec = grafo[act][i];
		if(color[vec] == -1) {
			paint(vec, grafo, color, actc^1);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vvi grafo(n);
	forn(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	vi color(n, -1);
	paint(0, grafo, color, 0);
	
	int c0 = 0, c1 = 0;
	forn(i, n) {
		if(color[i] == 0) c0++; else c1++;
	}
	cout << max(0, min(c0, c1) - 1) << endl;
}