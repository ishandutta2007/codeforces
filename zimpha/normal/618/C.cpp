#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef LL flt;
typedef pair<int, int> PII;
int sgn(flt x) {
  if (x < 0) return -1;
  else return x > 0;
}
const int MAXN = 100000 + 10;
struct Point {
  flt x, y;
  int idx;
  Point(flt a=0, flt b=0) : x(a), y(b) {}
  Point operator *(const flt &k) const {return Point(x*k,y*k);}
  Point operator /(const flt &k) const {return Point(x/k,y/k);}
  Point operator -(const Point &r) const {return Point(x-r.x,y-r.y);}
  Point operator +(const Point &r) const {return Point(x+r.x,y+r.y);}
  flt dot(const Point &r) {return x*r.x+y*r.y;}
  flt det(const Point &r) {return x*r.y-y*r.x;}
  flt sqr() {return x*x+y*y;}
  flt abs() {return hypot(x, y);}
} P[MAXN];

bool cmp(Point &A, Point &B) {
  return A.x < B.x || (A.x == B.x && A.y < B.y);
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%lld%lld", &P[i].x, &P[i].y);
    P[i].idx = i + 1;
  }
  sort(P, P + n, cmp);
  Point A = P[0], B = P[1];
  Point AB = B - A;
  int ret = -1;
  double mx = 0;
  for (int j = 2; j < n; ++ j) {
    if (AB.det(P[j] - A) != 0) {
      double dis = 1.0 * abs(AB.det(P[j] - A)) / AB.abs();
      if (ret == -1 || dis < mx) ret = j, mx = dis;
    }
  }
  cout << P[0].idx << " " << P[1].idx << " " << P[ret].idx << endl;
  return 0;
}