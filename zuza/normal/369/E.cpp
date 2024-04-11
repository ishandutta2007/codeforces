/******* Ortogonalna struktura, tested (CF 216 prob E) *******/

#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

struct Point {
  int x, y;
};

struct Ortho {
  struct Node {
    vector<int> ys;
    vector<int> left_lb;
    vector<int> right_lb;
  };
  vector<Node> data;
  const vector<Point>& pts;
  int n;
  int offset;

  Ortho(vector<Point>& pts) : pts(pts) {
    n = (int)pts.size();
    offset = 2; for (; offset < n; offset *= 2);
    data.resize(2*offset);
    build(1, 0, offset);
  }

  void build(int x, int lo, int hi) {
    if (x >= offset) {
      assert(lo == hi-1);
      assert(x-offset == lo);
      if (lo < (int)pts.size()) {
        data[x].ys.resize(1, pts[lo].y);
      }
      return ;
    }
    build(2*x, lo, (lo+hi)/2);
    build(2*x+1, (lo+hi)/2, hi);
    vector<int>& A = data[2*x].ys;
    vector<int>& B = data[2*x+1].ys;
    int a = 0, b = 0;
    int ab = 0;
    data[x].ys.resize(A.size() + B.size());
    data[x].left_lb.resize(A.size() + B.size() + 1);
    data[x].right_lb.resize(A.size() + B.size() + 1);

    while (a < (int)A.size() || b < (int)B.size()) {
      if (b < (int)B.size() && (a == (int)A.size() || B[b] < A[a])) {
        data[x].ys[ab] = B[b];
        data[x].left_lb[ab] = a;
        data[x].right_lb[ab] = b;
        ++b;
        ++ab;
      } else {
        data[x].ys[ab] = A[a];
        data[x].left_lb[ab] = a;
        data[x].right_lb[ab] = b;
        ++a;
        ++ab;
      }
    }

    data[x].left_lb[ab] = a;
    data[x].right_lb[ab] = b;
    assert(ab == (int)A.size() + (int)B.size());
  }

  int Ly, Ry;
  int Lx, Rx;

  int query(int loX, int hiX, int loY, int hiY) { // [lo, hi)
    Lx = loX; Rx = hiX;
    Ly = loY; Ry = hiY;
    int lo_ptr = lower_bound(data[1].ys.begin(), data[1].ys.end(), loY) - data[1].ys.begin();
    int hi_ptr = lower_bound(data[1].ys.begin(), data[1].ys.end(), hiY) - data[1].ys.begin();
    return down_query(1, 0, offset, lo_ptr, hi_ptr);
  }

  int down_query(int x, int lo, int hi, int lo_ptr, int hi_ptr) {
    if (Rx <= lo || hi <= Lx) {
      return 0;
    }
    if (Lx <= lo && hi <= Rx) {
      return hi_ptr - lo_ptr;
    }
    int sum = 0;
    sum += down_query(2*x, lo, (lo+hi)/2, data[x].left_lb[lo_ptr], data[x].left_lb[hi_ptr]);
    sum += down_query(2*x+1, (lo+hi)/2, hi, data[x].right_lb[lo_ptr], data[x].right_lb[hi_ptr]);
    return sum;
  }
};

int main(void)
{
  int n_p, n_q; scanf("%d %d", &n_p, &n_q);
  vector<Point> pts;

  REP(i, n_p) { // point = intervali
    int lo, hi; scanf("%d %d", &lo, &hi);
    pts.push_back({lo, hi});
  }

  sort(pts.begin(), pts.end(), [](Point a, Point b) { return a.x < b.x; });
  vector<int> xs;
  for (auto p : pts) xs.push_back(p.x);

  const int inf = 1e9;
  Ortho ortho(pts);

  REP(i_q, n_q) {
    int k; scanf("%d", &k);
    int left = 0;
    int cnt = 0;
    REP(i_k, k) {
      int p; scanf("%d", &p);
      int right = upper_bound(xs.begin(), xs.end(), p) - xs.begin();
      cnt += ortho.query(left, right, p, inf);
      left = right;
    }
    printf("%d\n", cnt);
  }

  return 0;
}