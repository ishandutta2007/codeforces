#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
using namespace std;
const int MN = 2e5 + 44;
VI graf[MN];
void err() {
	printf("-1\n");
	exit(0);
}
int equal(int x, int y) {
	int val = -1;
	for (auto v : graf[x]) {
		if (v != y) {
			int curr = equal(v, x);
			if (curr != val && val != -1) {
				debug("saw %d and %d in %d\n", curr, val, x);
				err();
			}
			val = curr;
		}
	}
	return val + 1;
}
//distant, vertex
pair <int, int> furthest(int x, int y = -1) {
	pair <int, int> res = MP(-1, x);
	for (auto v : graf[x])
		if (v != y)
			maxi(res, furthest(v, x));
	res.f++;
	return res;
}
bool dfs_path(int x, int y, int dest, vector <int> & path) {
	if (x == dest) {
		path.push_back(x);
		return true;
	}
	for (auto v : graf[x]) {
		if (v != y) {
			if (dfs_path(v, x, dest, path)) {
				path.push_back(x);
				return true;
			}
		}
	}
	return false;
}
vector <int> find_path(int a, int b) {
	vector <int> path;
	dfs_path(a, -1, b, path);
	return path;
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
	}
	int a = furthest(1, -1).second;
	int b = furthest(a, -1).second;
	vector <int> diameter = find_path(a, b);
	int res = 0;
	if (diameter.size() % 2) {
		int center = diameter[diameter.size() / 2];
		debug("one center %d\n", center);
		set <int> a;
		for (auto x : graf[center]) {
			a.insert(equal(x, center));
			if (a.size() > 2) {
				debug("to much\n");
				err();
			}
		}
		for (auto s : a) {
			debug("add %d\n", s);
			res += 1 + s;
		}
	}
	else {
		int center1 = diameter[diameter.size() / 2 - 1], center2 = diameter[diameter.size() / 2];
		debug("two centers %d and %d\n", center1, center2);
		res = 1 + equal(center1, center2) + equal(center2, center1);
	}
	debug("res1 = %d\n", res);
	while (res % 2 == 0)
		res /= 2;
	printf("%d\n", res);
}