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

struct rmq {
	vector<double> v;
	vector<double> mul;
	vector<double> add;
};

rmq init(tint n, vector<tint>& a) {
	tint p = 1;
	while(p < n) p *= 2;
	tint s = 2*p;
	rmq tree;
	tree.v = vector<double>(s, 0);
	tree.mul = vector<double>(s, 1);
	tree.add = vector<double>(s, 0);
	
	forn(i, a.size()) {
		tree.v[i+p] = a[i];
	}
	
	dforn(i, p) if(i) {
		tree.v[i] = tree.v[2*i]+tree.v[2*i+1];
	}
	
	return tree;
}

void prop(rmq& tree, int n) {
	for(int i = 2*n; i < 2*n+2; i++) {
		tree.mul[i] *= tree.mul[n];
		tree.add[i] *= tree.mul[n];
		tree.add[i] += tree.add[n]/2;
	}
	tree.v[n] = tree.v[n]*tree.mul[n]+tree.add[n];
	tree.mul[n] = 1;
	tree.add[n] = 0;
}

double get(rmq& tree, int n, int a, int b, int l, int r) {
	if(l>=b || r<=a) return 0;
	if(a<=l && r<=b) return tree.v[n]*tree.mul[n]+tree.add[n];
	
	prop(tree, n);
	return get(tree, 2*n, a, b, l, (r+l)/2)+get(tree, 2*n+1, a, b, (l+r)/2, r);
}


double get(rmq& tree, int a, int b) {
	return get(tree, 1, a, b, 0, tree.v.size()/2);
}

void update(rmq& tree, double mul, double add, int n, int a, int b, int l, int r) {
	if(l>=b || r<=a) return;
	if(a<=l && r<=b) {
		tree.mul[n] *= mul;
		tree.add[n] *= mul;
		tree.add[n] += (r-l)*add;
		return;
	}
	
	prop(tree, n);
	update(tree, mul, add, 2*n, a, b, l, (l+r)/2);
	update(tree, mul, add, 2*n+1, a, b, (l+r)/2, r);
	tree.v[n] = get(tree, 2*n, l, (l+r)/2, l, (l+r)/2) + get(tree, 2*n+1, (l+r)/2, r, (l+r)/2, r);
}

void update(rmq& tree, double mul, double add, int a, int b) {
	return update(tree, mul, add, 1, a, b, 0, tree.v.size()/2);
}

int main()
{
	//freopen("E.in","r",stdin);
	tint n, q;
	cin >> n >> q;
	vector<tint> a(n);
	forn(i,n) cin >> a[i];
	rmq tree = init(n, a);
	
	forn(i,q) {
		int tq;
		cin >> tq;
		if(tq == 1) {
			tint l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--; l2--;
			double s1 = get(tree, l1, r1), s2 = get(tree, l2, r2);
			double m1 = (r1-l1-1)/(double) (r1-l1), m2 = (r2-l2-1)/(double) (r2-l2);
			double r = (r1-l1)*(r2-l2);
			update(tree, m1, s2/r, l1, r1);
			update(tree, m2, s1/r, l2, r2);
		} else {
			tint l, r;
			cin >> l >> r;
			l--;
			printf("%.9f\n", get(tree, l, r));
		}
	}
	return 0;
}