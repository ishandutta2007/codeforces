#include <stdio.h>
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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

const int N = 105;
vi x(2), y(2);
/*int d[N][N][N][N];
  int a[N][N];

  int solve(int lx, int rx, int ly, int ry) {
  if (lx >= rx || ly >= ry) return 0;
  if (d[lx][rx][ly][ry] >= 0) return d[lx][rx][ly][ry];
  int res = min(x[rx] - x[lx], y[ry] - y[ly]);  
  if (max(rx - lx, ry - ly) == 1 && a[rx][ry] == 0) {
  res = 0;
  }
  for (int i = ly + 1; i < ry; ++i) {
  res = min(res, solve(lx, rx, ly, i) + solve(lx, rx, i, ry));
  }
  for (int i = lx + 1; i < rx; ++i) {
  res = min(res, solve(lx, i, ly, ry) + solve(i, rx, ly, ry));
  }
  d[lx][rx][ly][ry] = res;
  return res;
  }*/

void makeu(vi& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  assert(v.size() < N);
}

struct TEdge {
  int from, to;
  ll capacity, flow;
  TEdge* reverse;
};

TEdge edgePool[1000000];
int edgePoolPtr = 0;

typedef vector<TEdge*> ve;
vector< ve > edges; //resize

int SOURCE, TARGET; //assign

TEdge* AddEdge(int from, int to, ll capacity) {
  TEdge* e1 = &edgePool[edgePoolPtr++];
  TEdge* e2 = &edgePool[edgePoolPtr++];
  TEdge fw = {from, to, capacity, 0, e2};
  TEdge bw = {to, from, 0, 0, e1};
  *e1 = fw;
  *e2 = bw;
  edges[from].push_back(e1);
  edges[to].push_back(e2);
  return e1;
}

inline ll AvailableCapacity(const TEdge* p) {
  return (p->capacity - p->flow);
}

class TDinic {
  public:
    vector<int> Distances;
    vector<size_t> Ptr;
    int N;
    void BFS() {
      deque<int> q;
      Distances.assign(N, -1);
      Distances[SOURCE] = 0;
      q.push_back(SOURCE);
      while (!q.empty()) {
        int p = q.front();
        q.pop_front();
        for (size_t i = 0; i < edges[p].size(); i++) {
          if (!AvailableCapacity(edges[p][i]))
            continue;
          int c = edges[p][i]->to;
          if (Distances[c] == -1) {
            Distances[c] = Distances[p] + 1;
            q.push_back(c);
          }
        }
      }
    }
    ll DFS(int p, ll fl) {
      if (fl == 0)
        return 0;
      if (p == TARGET)
        return fl;
      ll res = 0;

      for (size_t &i = Ptr[p]; Ptr[p] < edges[p].size() && fl != 0; ++i) {
        if (!AvailableCapacity(edges[p][i])) {
          continue;
        }
        if (Distances[edges[p][i]->from] + 1 != Distances[edges[p][i]->to])
          continue;
        ll pushed = DFS(edges[p][i]->to, min(fl, AvailableCapacity(edges[p][i])));
        fl -= pushed;
        res += pushed;
        edges[p][i]->flow += pushed;
        edges[p][i]->reverse->flow -= pushed;
        if (fl == 0)
          break;
      }
      return res;
    }
    /*void init() {
      SOURCE,TARGET
      edges.clear();
      edgePoolPtr = 0;
      edges.resize();
      }*/
    ll calc_max_flow() {
      N = (int)edges.size();
      ll res = 0;
      while (true) {
        BFS();
        Ptr.assign(N, 0);
        ll p = DFS(SOURCE, 1e18);
        if (!p)
          break;
        res += p;
      }
      return res;
    }
};

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 1e9, m = 50;
  if (!DEBUG) cin >> n >> m;
  x[1] = y[1] = n;
  vector<array<int, 4>> rect;
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    if (!DEBUG) {
      cin >> a >> b >> c >> d;
      --a; --b; --c; --d;
    } else {
      a = rand() % n;
      b = rand() % n;
      c = rand() % n;
      d = rand() % n;
      if (a > c) swap(a, c);
      if (b > d) swap(b, d);
    }
    x.push_back(a);
    x.push_back(c + 1);
    y.push_back(b);
    y.push_back(d + 1);
    rect.push_back({a, b, c + 1, d + 1});
  }
  makeu(x);
  makeu(y);
  SOURCE = x.size() + y.size();
  TARGET = SOURCE + 1;
  edges.clear();
  edgePoolPtr = 0;
  edges.resize(TARGET + 1);
  for (int i = 0; i < (int)x.size(); ++i) {
    AddEdge(SOURCE, i, x[i + 1] - x[i]);
  }
  for (int i = 0; i < (int)y.size(); ++i) {
    AddEdge(i + x.size(), TARGET, y[i + 1] - y[i]);
  }
  for (auto v : rect) {
    int x1 = lower_bound(x.begin(), x.end(), v[0]) - x.begin();  
    int y1 = lower_bound(y.begin(), y.end(), v[1]) - y.begin();  
    int x2 = lower_bound(x.begin(), x.end(), v[2]) - x.begin();  
    int y2 = lower_bound(y.begin(), y.end(), v[3]) - y.begin();
    for (int i = x1; i < x2; ++i) for (int j = y1; j < y2; ++j) {
      AddEdge(i, x.size() + j, n);
    }
  }
  TDinic f;
  cout << f.calc_max_flow() << endl;
  return 0;
}