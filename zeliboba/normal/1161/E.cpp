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

vi p;
vii dif;
int n;
const int DEBUG = 0;
vi hidden;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  p[a] = b;
}

void ask(const vii& v) {
  if (v.empty()) return;
  assert(v.size() * 2 <= n);
  vi was(n);
  for (pii p : v) {
    was[p.first]++;
    was[p.second]++;
  }
  for (int i = 0; i < n; ++i) assert(was[i] <= 1);
  cout << "Q " << v.size();
  for (pii p : v) cout << ' ' << p.first + 1 << ' ' << p.second + 1;
  cout << endl;
  vi ans(v.size());
  if (DEBUG) {
    for (int i = 0; i < v.size(); ++i) {
      ans[i] = hidden[v[i].first] == hidden[v[i].second];
    }
  } else {
    string s;
    cin >> s;
    assert(s != "-1");
    for (int i = 0; i < v.size(); ++i) {
      ans[i] = s[i] - '0';
    }
  }
  for (int i = 0; i < v.size(); ++i) {
    if (ans[i]) {
      join(v[i].first, v[i].second);
    } else {
      dif.push_back(v[i]);
    }
  }
}

void answer() {
  vi roots;
  for (int i = 0; i < p.size(); ++i) if (p[i] == i) {
    roots.push_back(i);
  }
  vvi v(3);
  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) if (getp(i) == roots[j]) {
      v[j].push_back(i);
      break;
    }
  }
  cout << "A " << v[0].size() << ' ' << v[1].size() << ' ' << v[2].size() << '\n';
  for (int i = 0; i < v.size(); ++i) {
    for (int x : v[i]) cout << x + 1 << ' ';
    cout << endl;
  }
  if (DEBUG) {
    cerr << "hidden: ";
    for (int i = 0; i < n; ++i) cerr << hidden[i] << ' ';
    cerr << endl;
    cerr << "roots: ";
    for (int x : roots) cerr << x << ' ';
    cerr << endl;
    for (int i = 0; i < roots.size(); ++i) for (int j = i + 1; j < roots.size(); ++j) assert(hidden[roots[i]] != hidden[roots[j]]);
    for (int i = 0; i < roots.size(); ++i) {
      for (int x : v[i]) assert(hidden[x] == hidden[roots[i]]);
    }
  }
  assert(roots.size() <= 3);
}

vi bin(const vi& a, const vi& b) {
  vi res;
  for (int x : a) if (binary_search(b.begin(), b.end(), x)) res.push_back(x);
  return res;
}

vi inter(const vi& a, const vi& b) {
  if (min(a.size(), b.size()) * 5 < max(a.size(), b.size())) {
    if (a.size() < b.size()) return bin(a, b);
    else bin(b, a);
  }
  vi res;
  int it = 0;
  for (int x : a) {
    while (it < b.size() && b[it] < x) ++it;
    if (it < b.size() && b[it] == x) {
      res.push_back(x);
    }
  }
  return res;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  srand(131);
  int T = 5;
  if (!DEBUG) cin >> T;
  ll tot = 0;
  for (int test = 1; test <= T; ++test) {
    if (!DEBUG) cin >> n;
    else n = rand() % 100000 + 1;
    dif.clear();
    p.resize(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    if (DEBUG) {
      hidden.resize(n);
      for (int i = 0; i < n; ++i) {
        if (rand() % 3 == 0) hidden[i] = 0;
        else if (rand() % 2 == 0) hidden[i] = 1;
        else hidden[i] = 2;
      }
    }
    for (int t = 0; t < 7; ++t) {
      vii v;
      vvi comps;
      vi roots;
      map<int, int> ind;
      set<pii> was;
      for (pii p : dif) {
        int a = getp(p.first), b = getp(p.second);
        if (a > b) swap(a, b);
        was.insert(pii(a, b));    
      }
      for (int i = 0; i < p.size(); ++i) if (p[i] == i) {
        ind[i] = roots.size();
        roots.push_back(i);
      }
      comps.resize(roots.size());
      for (int i = 0; i < p.size(); ++i) {
        comps[ind[getp(i)]].push_back(i);
      }
      sort(comps.begin(), comps.end(), [&](const auto& a, const auto& b) {return a.size() < b.size();});
      for (int i = (int)comps.size() - 1; i >= 0; --i) {
        int j = i - 1;
        for (int x : comps[i]) {
          while (j >= 0) {
            if (comps[j].empty()) {
              --j;
              continue;
            }
            int pa = getp(x), pb = getp(comps[j][0]);
            if (pa > pb) swap(pa, pb);
            if (!was.count(pii(pa, pb))) break;
            --j;
          }
          if (j >= 0) {
            v.emplace_back(x, comps[j].back());
            comps[j].pop_back();
            --j;
          }
        }
      }
/*      vi x(n);
      for (int i = 0; i < n; ++i) {
        x[i] = i;
      }
      random_shuffle(x.begin(), x.end());
      for (int i = 0; i + 1 < n; i += 2) {
        v.emplace_back(x[i], x[i + 1]);
      }*/
      ask(v);
      for (int it = 0; it < (t < 6 ? 2 : 100); ++it) {
        //tot += 1;
        bool found = false;
        vvi g(n);
        set<pii> was;
        vii ndif;
        for (pii p : dif) {
          int a = getp(p.first), b = getp(p.second);
          assert(a != b);
          if (a > b) swap(a, b);
          if (was.count(pii(a, b))) continue;
          g[a].push_back(b);
          g[b].push_back(a);
          was.insert(pii(a, b));
          ndif.push_back(p);
        }
        for (int i = 0; i < g.size(); ++i) {
          sort(g[i].begin(), g[i].end());
        }
        dif = ndif;
        for (pii p : dif) {
          int a = getp(p.first), b = getp(p.second);
          vi v = inter(g[a], g[b]);
          //tot += g[a].size() + g[b].size();
          for (int i = 1; i < v.size(); ++i) {
            join(v[0], v[i]);
            found = true;
          }
        }
        if (!found) break;
      }
    }
    answer();
  }
  if (DEBUG) cerr << tot << endl;
  return 0;
}