#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Pt {
  int x, idx;
  friend bool operator < (Pt a, Pt b) {
    return a.x < b.x;
  }
};

vector<Pt> pts;

int get_idx(int x) { 
  return lower_bound(pts.begin(), pts.end(), (Pt){x, -1}) - pts.begin();
}

int solve(int i, int l) {
  int j = upper_bound(pts.begin(), pts.end(), (Pt){pts[i].x+l, -1}) - pts.begin() - 1;
  if (j != i) {
    l -= pts[j].x - pts[i].x;
    i = j;
  }

  j = lower_bound(pts.begin(), pts.end(), (Pt){pts[i].x-l, -1}) - pts.begin();
  if (i == j) return pts[i].idx;

  int t = pts[i].x - pts[j].x;
  l %= 2*t;

  j = lower_bound(pts.begin(), pts.end(), (Pt){pts[i].x-l, -1}) - pts.begin();
  t = pts[i].x - pts[j].x;
  if (i == j) return pts[i].idx;

  return solve(j, l-t);
}

int main(void) {
  int np, nq; scanf("%d %d", &np, &nq);
  vector<int> orig;
  REP(i, np) {
    int x; scanf("%d", &x);
    pts.push_back({x, i});
    orig.push_back(x);
  }
  sort(pts.begin(), pts.end(), [](Pt a, Pt b) {
      return a.x < b.x;
    });

  REP(iq, nq) {
    int i, l; scanf("%d %d", &i, &l); --i;
    printf("%d\n", solve(get_idx(orig[i]), l) + 1);
  }

  return 0;
}