#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 1e5 + 123;
const double eps = 1e-9;
struct Edge { int a, b; double w; };

int n;
vector<Edge> E[MAXN];

struct Pt { // 2D
  double x, y, z;
  Pt(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  friend Pt operator - (Pt a, Pt b) { return {a.x-b.x, a.y-b.y, a.z-b.z}; }
  friend double dot(Pt a, Pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
  friend Pt cross(Pt a, Pt b) {
    return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x };
  }
};

struct Line { 
  Pt a, b;
  int idx;
  Pt get_abc() const { 
    Pt ans = cross((Pt){a.x, a.y, 1}, {b.x, b.y, 1});
    assert(dot({a.x, a.y, 1}, ans) == 0);
    assert(dot({b.x, b.y, 1}, ans) == 0);
    return ans;
  }
  friend Pt presjek(const Line& a, const Line& b) {
    Pt a_abc = a.get_abc();
    Pt b_abc = b.get_abc();
    Pt ans = cross(a_abc, b_abc);
    assert(ans.z != 0);    
    return {ans.x/ans.z, ans.y/ans.z, 0};
  }
  double minx() const { return min(a.x, b.x); }
  double maxx() const { return max(a.x, b.x); }
};

enum { BOTTOM, TOP };
struct Evt {
  int type; // 0 = add, 1 = del
  int enda, endb;
  int bottom;

  Pt curr;
  int curr_idx;
};

struct LineCmpf {
  bool operator () (const Line& a, const Line& b) const {
    double lo = max(a.minx(), b.minx()), hi = min(a.maxx(), b.maxx());
    double mid = (lo + hi) / 2;
    Line L = {(Pt){mid, 0}, (Pt){mid, 1}};
    double a_y = presjek(L, a).y, b_y = presjek(L, b).y;
    return make_tuple(a_y, a.minx()) < make_tuple(b_y, b.minx());
  }
};

inline double get_dist(Pt a, Pt b) { double dx = a.x-b.x, dy = a.y-b.y; return sqrt(dx*dx + dy*dy); }

double dijkstra(int s, int t) {
  const int inf = 1e9;
  static vector<double> dist; dist.clear(); dist.resize(n, inf);
  static vector<int> bio; bio.clear(); bio.resize(n, false);
  auto cmp = [](int a, int b) {
    return make_pair(dist[a], a) < make_pair(dist[b], b);
  };

  set<double, decltype(cmp)> pq(cmp);
  dist[s] = 0;
  pq.insert(s);

  for (; !pq.empty(); ) {
    int ex = *pq.begin(); pq.erase(pq.begin());
    bio[ex] = true;
    for (Edge e : E[ex]) {
      if (bio[e.b]) continue;
      double val = dist[e.a] + e.w;
      if (val+eps < dist[e.b]) {        
        if (dist[e.b] < inf) pq.erase(e.b);
        dist[e.b] = val;
        pq.insert(e.b);
      }
    }
  }

  return dist[t];
}

int main(void)
{
  scanf("%d", &n);
  vector<Pt> P;
  REP(i, n) {
    double x, y; scanf("%lf %lf", &x, &y); x += 1e4;
    P.push_back({x, y, 0});
  } // ccw smjer

  const int MAXCOOR = 2e4 + 213;
  static vector<Evt> evts[MAXCOOR];
  REP(i, n) {
    int j = i+1; if (j == n) j = 0;
    Pt left = P[i], right = P[j]; int l_idx = i, r_idx = j;
    if (left.x > right.x) { swap(left, right); swap(l_idx, r_idx); }
    if (P[i].x == P[j].x) {
      // vert
    } else if (P[i].x < P[j].x) { // bottom
      evts[(int)left.x].push_back({0, i, j, BOTTOM, left, l_idx});
      evts[(int)right.x].push_back({1, i, j, BOTTOM, right, r_idx});
    } else if (P[i].x > P[j].x) { // top
      evts[(int)left.x].push_back({0, i, j, TOP, left, l_idx});
      evts[(int)right.x].push_back({1, i, j, TOP, right, r_idx});
    }
  }

  set<Line, LineCmpf> pq;
  REP(x, MAXCOOR) {
    if (evts[x].empty()) continue;
    for (Evt e : evts[x]) {
      if (e.type == 0) { // add
        Line L = {P[e.enda], P[e.endb], e.enda};
        pq.insert(L);
      }
    }
    
    // ADD PTS
    for (Evt e : evts[x]) {
      Line L = {P[e.enda], P[e.endb], e.enda};
      auto it = pq.find(L);
      assert(it != pq.end());

      Line x_line = {{(double)x, 0.}, {(double)x, 1.}};

      if (e.bottom == TOP && it != pq.begin()) { // 1 prije
        auto it2 = prev(it); // ne koristi it
        Pt donja = presjek(x_line, *it2);
        for (int d_idx : {it2->idx, (it2->idx+1)%n}) {
          int a = e.curr_idx;
          int b = d_idx;
          double d = get_dist(e.curr, donja) + get_dist(donja, P[d_idx]);
          E[a].push_back({a, b, d});
          //            TRACE(a _ b _ d);
        }
      }

      if (e.bottom == BOTTOM) {
        auto it2 = next(it); // ne koristi it
        if (it2 != pq.end()) {
          Pt gornja = presjek(x_line, *it2);
          for (int g_idx : {it2->idx, (it2->idx+1)%n}) {
            int a = g_idx;
            int b = e.curr_idx;
            double d = get_dist(P[g_idx], gornja) + get_dist(gornja, e.curr);
            E[a].push_back({a, b, d});            
            //            TRACE(a _ b _ d);
          }
        }
      }
    }


    // REMOVE
    for (Evt e : evts[x]) {
      if (e.type == 1) { // remove
        Line L = {P[e.enda], P[e.endb], e.enda};
        pq.erase(L);
      }
    }
  }

  // popuni edgeve
  REP(i, n) {
    int j = i+1; if (j == n) j = 0;
    E[i].push_back({i, j, get_dist(P[i], P[j])});
    E[j].push_back({j, i, get_dist(P[i], P[j])});
  }

  int s, t; scanf("%d %d", &s, &t); --s, --t;
  double ans = dijkstra(s, t);
  printf("%.9lf\n", ans);
  
  return 0;
}