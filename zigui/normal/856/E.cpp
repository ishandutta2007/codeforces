#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

pii operator-(const pii &l, const pii &r) {
	return pii(l.first - r.first, l.second - r.second);
}

ll operator/(const pii &l, const pii &r) {
	return (ll)l.first * r.second - (ll)l.second * r.first;
}
ll operator*(const pii &l, const pii &r) {
	return (ll)l.first * r.first + (ll)l.second * r.second;
}

const int MX = 1<<19;

int ord[MX][3], sz = 0;
pii D[MX];

auto cw = [](pii l, pii r) { return l / r < 0; };

struct Tree {
	int t[MX * 2];
	int read(int s, int e) {
		s += MX, e += MX;
		int r = 0;
		while (s <= e) {
			if (s & 1) r = max(r, t[s++]);
			if (~e & 1) r = max(r, t[e--]);
			s /= 2, e /= 2;
		}
		return r;
	}
	void update(int x, int v) {
		x += MX; t[x] = v;
		while (x > 1) {
			x /= 2; t[x] = max(t[x * 2], t[x * 2 + 1]);
		}
	}
} tree;
set<int> P[MX];

void add_point(int a, int b) {
	P[a].insert(b);
	tree.update(a, *P[a].rbegin());
}

void erase_point(int a, int b) {
	P[a].erase(b);
	tree.update(a, P[a].empty()? 0 : *P[a].rbegin());
}

bool solve(int a, int b) {
	if (tree.read(0, a) >= b) return true;
	return false;
}

int main()
{
	int N, R;
	vector<pii> X, Y;
	scanf("%d%d", &R, &N);
	pii A = pii(-R, 0), B = pii(R, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) scanf("%d", ord[i] + j);
		if (ord[i][0] != 2) scanf("%d", ord[i] + 2);
		if (ord[i][0] == 1) {
			D[++sz] = pii(ord[i][1], ord[i][2]);
			X.push_back(D[sz] - A);
			Y.push_back(D[sz] - B);
		}
	}
	sort(X.begin(), X.end(), cw);
	sort(Y.begin(), Y.end(), cw);
	auto V = [](vector<pii> &X, pii x) {
		return lower_bound(X.begin(), X.end(), x, cw) - X.begin() + 1;
	};

	for (int i = 1; i <= N; i++) {
		int o = ord[i][0], x = ord[i][1], y = ord[i][2];
		if (o == 1) {
			int a = V(X, pii(x, y) - A), b = V(Y, pii(x, y) - B);
			add_point(a, b);
		}
		else if(o == 2){
			int a = V(X, D[x] - A), b = V(Y, D[x] - B);
			erase_point(a, b);
		}
		else {
			int a = V(X, D[x] - A), b = V(Y, D[x] - B);
			int p = V(X, D[y] - A), q = V(Y, D[y] - B);
			int u = max(a, p), v = min(b, q);
			erase_point(a, b);
			erase_point(p, q);
			if (X[u-1] * Y[v-1] >= 0 && !solve(u, v)) printf("YES\n");
			else printf("NO\n");
			add_point(a, b);
			add_point(p, q);
		}
	}
	return 0;
}
/*
5 8
1 -5 8
1 -4 8
1 -3 8
1 3 7
3 1 3
2 2
3 1 3
3 3 4
*/