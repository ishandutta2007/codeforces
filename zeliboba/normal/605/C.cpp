#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

double mdiv(int a, int b) {
  if (a == 0) return 0;
  if (b == 0) return 1e18;
  return a / (double) b;
}

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<pt> v(n);
    double res = 1e18;
    for (int i = 0; i < n; ++i) {
      int a,b;
      scanf("%d%d",&a,&b);
      v[i].x = a;
      v[i].y = b;
      res = min(res, max(mdiv(p, a), mdiv(q, b)));
    }
    convex_hull(v);
    v.push_back(v[0]);
    for (int i = 0; i + 1 < v.size(); ++i) {
      double det = v[i].x*v[i+1].y - v[i+1].x*v[i].y;
      if (abs(det) < 1e-8) continue;
      double a = (v[i+1].y*p-v[i+1].x*q) / det;
      double b = (-v[i].y*p+v[i].x*q) / det;
//      cerr << a << ' ' << b << endl;
      if (a > 1e-8 && b > 1e-8) {
        res = min(res, a + b);
      }
    }
    printf("%.10lf\n", res);
    return 0;
}