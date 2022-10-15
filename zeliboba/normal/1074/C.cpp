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
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int dist(const pii& a, const pii& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int per(const pii& a, const pii& b, const pii& c) {
  return dist(a, b) + dist(b, c) + dist(a, c);
}

int per(const array<int, 3>& ind, const vii& p) {
  return per(p[ind[0]], p[ind[1]], p[ind[2]]);
}

int nx(int i, int n) {
  i += 1;
  if (i >= n) i -= n;
  return i;
}

int pr(int i, int n) {
  i -= 1;
  if (i < 0) i += n;
  return i;
}

void local(array<int, 3>& ind, int& P, const vii& p) {
  int n = p.size();
  while (1) {
    int P0 = P;
    for (int i = 0; i < 3; ++i) {
      while (1) {
        ind[i] = nx(ind[i], n);
        int curP = per(ind, p);
        if (curP > P) {
          P = curP;
        } else {
          ind[i] = pr(ind[i], n);
          break;
        }
      }
      while (1) {
        ind[i] = pr(ind[i], n);
        int curP = per(ind, p);
        if (curP > P) {
          P = curP;
        } else {
          ind[i] = nx(ind[i], n);
          break;
        }
      }
    }
    if (P0 == P) break;
  }
}

int stupid(const vii& p) {
  int n = p.size();
  int res = 0;
  for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int l = j; l < n; ++l) {
    res = max(res, per({i, j, l}, p));
  }
  return res;
}

int calcp3(const vii& p) {
  int n = p.size();
  int res = 0;
  for (int t = 0; t < 10; ++t) {
    int a = rand() % n;
    int b = a, c = a;
    while (b == a) b = rand() % n;
    while (c == a || c == b) c = rand() % n;
    int P = per(p[a], p[b], p[c]);
    array<int, 3> ind = {a, b, c};
    sort(ind.begin(), ind.end());
    local(ind, P, p);
    res = max(res, P);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        int prev = ind[i];
        ind[i] = j;
        int curP = per(ind, p);
        if (curP > P) {
          P = curP;
        } else {
          ind[i] = prev;
        }
      }
    }
    local(ind, P, p);
    res = max(res, P);
/*    auto ind0 = ind;
    for (int i = 0; i < 3; ++i) {
      ind = ind0;
      ind[i] = nx(ind[(i + 1) % 3], n);
      swap(ind[0], ind[i]);
      P = per(ind, p);
      local(ind, P, p);
      res = max(res, P);
    }*/
  }
  if (n <= 100) {
    assert(res == stupid(p));
  }
  return res;
}

int main() {
  srand(3471293857426578924165789241658712465897612487956247831426589724);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii p(n);
  int minx = 1e9, miny = 1e9, maxx = -1e9, maxy = -1e9;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
    minx = min(minx, p[i].first);
    maxx = max(maxx, p[i].first);
    miny = min(miny, p[i].second);
    maxy = max(maxy, p[i].second);
  }
  vi good;
  for (int i = 0; i < n; ++i) {
    if (p[i].first == minx || p[i].first == maxx || p[i].second == miny || p[i].second == maxy) {
      good.push_back(i);
    }
  }
  int res3 = calcp3(p);
  for (int i = 0; i < (int)good.size(); ++i) for (int j = i + 1; j < (int)good.size(); ++j) {
    for (int l = 0; l < n; ++l) {
      res3 = max(res3, per({good[i], good[j], l}, p));
    }
  }
  cout << res3;
  for (int i = 4; i <= n; ++i) {
    cout << ' ' << 2 * (maxx - minx + maxy - miny);
  }
  cout << endl;
  return 0;
}