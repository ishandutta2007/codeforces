///////////////////////////////    _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 200005;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int C2(int n) {
  int answ = n * 1ll * (n - 1) % mod;
  return answ * 1ll * ((mod + 1) / 2) % mod;
}

int calc(int x, int all) {
  int answ = (all - x) * 1ll * C2(x) % mod;
  answ += x * 1ll * C2(all - x) % mod;
  answ %= mod;
  return answ;
}

int n;

int a[N];
vector <int> mas[N];

vector <int> g[N];

int sz[N];
int all[N], lp[N];
unordered_map <int, int> mp[N];

int cur;
int answ;

void rec(int v, int p) {
  sz[v] = 1;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    rec(to, v);
    sz[v] += sz[to];
  }
}

void dfs(int v, int p) {
  int mx = -1, big;

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    if (sz[to] > mx) {
      mx = sz[to];
      big = to;
    }
  }

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (to == p || to == big) continue;
    cur = 0;
    dfs(to, v);
  }

  if (mx != -1) {
    cur = 0;
    dfs(big, v);
    swap(mp[big], mp[v]);
  }

  for (int pr: mas[v]) {
    if (mp[v].find(pr) == mp[v].end()) {
      cur += calc(1, all[pr]);
      cur %= mod;
      mp[v][pr] = 1;
    } else {
      cur += mod - calc(mp[v][pr], all[pr]);
      cur %= mod;
      mp[v][pr]++;
      cur += calc(mp[v][pr], all[pr]);
      cur %= mod;
    }
  }

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    for (auto it = mp[to].begin(); it != mp[to].end(); ++it) {
      int pr = it -> first;
      int cnt = it -> second;
      ///
      if (mp[v].find(pr) == mp[v].end()) {
        cur += calc(cnt, all[pr]);
        cur %= mod;
        mp[v][pr] = cnt;
      } else {
        cur += mod - calc(mp[v][pr], all[pr]);
        cur %= mod;
        mp[v][pr] += cnt;
        cur += calc(mp[v][pr], all[pr]);
        cur %= mod;
      }
    }
    mp[to].clear();
  }

  // cout << v << " " << p << endl;

  answ += cur;
  answ %= mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      for (int j = i; j < N; j += i) {
        lp[j] = i;
      }
    }
  }

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (a[i] != 1) {
      if ((int)mas[i].size() > 0 && mas[i].back() == lp[a[i]]) {

      } else {
        mas[i].push_back(lp[a[i]]);
      }
      a[i] /= lp[a[i]];
    }
    ///
    for (int pr: mas[i]) {
      all[pr]++;
    }
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rec(1, -1);
  dfs(1, -1);

  cout << answ << endl;
  return 0;
}