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
#define TOT 101
typedef long long tint;
using namespace std;

struct rmq {
	vector<vector<int>> p;
	vector<int> ch;
	int n;	
};

void propagate(rmq& rm, int i) {
	forn(j, TOT) {
		rm.p[2*i][j] = rm.p[i][rm.p[2*i][j]];
		rm.p[2*i+1][j] = rm.p[i][rm.p[2*i+1][j]];
	}
	
	forn(j, TOT) {
		rm.p[i][j] = j;
	}
	rm.ch[i] = 0;
	rm.ch[2*i] = 1;
	rm.ch[2*i+1] = 1;
}

void update(rmq& rm, int i, int a, int b, int l, int r, int x, int y) {
	if(b <= l || r <= a) return;
	if(l <= a && b <= r) {
		forn(j, TOT) if(rm.p[i][j] == x) rm.p[i][j] = y;
		if(i < rm.n) rm.ch[i] = 1;
		return;
	}
	
	if(rm.ch[i]) propagate(rm, i);
	update(rm, 2*i, a, (a+b)/2, l, r, x, y);
	update(rm, 2*i+1, (a+b)/2, b, l, r, x, y);
}

void update(rmq& rm, int l, int r, int x, int y) {
	update(rm, 1, 0, rm.n, l, r, x, y);
}

void propagateAll(rmq& rm) {
	forn(i, rm.n) {
		if(rm.ch[i]) propagate(rm, i);
	}
}

rmq init(int n) {
	int t = 1;
	while(t < n) t *= 2;
	rmq ans;
	ans.n = t;
	ans.p.resize(2*t);
	forn(i, 2*t) {
		forn(j, TOT) ans.p[i].push_back(j);
	}
	ans.ch = vector<int>(2*t, 0);
	return ans;
}


int main()
{
	int n;
	cin >> n;
	rmq perms = init(n);
	vector<int> a(n);
	forn(i, n) scanf("%i", &(a[i]));
	int q;
	cin >> q;
	forn(i, q) {
		int a, b, x, y;
		scanf("%i %i %i %i", &a, &b, &x, &y);
		a--;
		update(perms, a, b, x, y);
	}
	propagateAll(perms);
	forn(i, n) {
		if(i) printf(" ");
		printf("%i", perms.p[i+perms.n][a[i]]);
	}
	printf("\n");
	
	return 0;
}