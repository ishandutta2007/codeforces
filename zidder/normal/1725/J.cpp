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

const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n;

vector < pair<int, int> > g[N];

long long dp1[N], dp2[N], dp3[N], dp4[N];
long long D[N];

long long Dup[N], dpup[N];

long long sum;
long long answ = inf * 1ll * inf;

void dfs(int v, int p) {
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    
    if (to == p) continue;

    dfs(to, v);

    D[v] = max(D[v], D[to]);
    if (dp1[to] + len > dp1[v]) {
      dp4[v] = dp3[v];
      dp3[v] = dp2[v];
      dp2[v] = dp1[v];
      dp1[v] = dp1[to] + len;
    } else if (dp1[to] + len > dp2[v]) {
      dp4[v] = dp3[v];
      dp3[v] = dp2[v];
      dp2[v] = dp1[to] + len;
    } else if (dp1[to] + len > dp3[v]) {
      dp4[v] = dp3[v];
      dp3[v] = dp1[to] + len;
    } else if (dp1[to] + len > dp4[v]) {
      dp4[v] = dp1[to] + len;
    }
  }
  D[v] = max(D[v], dp1[v] + dp2[v]);
}

void dfsup(int v, int p) {
  multiset <long long> q;

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    if (to == p) continue;
    q.insert(D[to]);
  }

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    if (to == p) continue;
    ///
    dpup[to] = dpup[v] + len;
    if (dp1[to] + len == dp1[v]) {
      dpup[to] = max(dpup[to], dp2[v] + len);
    } else {
      dpup[to] = max(dpup[to], dp1[v] + len);
    }
    ///
    Dup[to] = Dup[v];

    q.erase(q.find(D[to]));
    if ((int)q.size() > 0) {
      long long mx = *(--q.end());
      Dup[to] = max(Dup[to], mx);
    }

    if (dp1[to] + len == dp1[v]) {
      Dup[to] = max(Dup[to], dp2[v] + dp3[v]);
      Dup[to] = max(Dup[to], dp2[v] + dpup[v]);
    } else if (dp1[to] + len == dp2[v]) {
      Dup[to] = max(Dup[to], dp1[v] + dp3[v]);
      Dup[to] = max(Dup[to], dp1[v] + dpup[v]);
    } else {
      Dup[to] = max(Dup[to], dp1[v] + dp2[v]);
      Dup[to] = max(Dup[to], dp1[v] + dpup[v]);
    }

    q.insert(D[to]);
  }

  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    if (to == p) continue;
    dfsup(to, v);
  }
}

void solve(int v, int p) {
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    if (to == p) continue;
    solve(to, v);
    answ = min(answ, sum - 2 * len - D[to] - Dup[to]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    sum += 2 * c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }

  dfs(1, -1);
  dfsup(1, -1);
  solve(1, -1);

  for (int i = 1; i <= n; i++) {
    long long cur = sum;
    cur -= dp1[i];
    cur -= dp2[i];
    cur -= dp3[i];
    cur -= max(dp4[i], dpup[i]);
    answ = min(answ, cur);
  }

  cout << answ << endl;
  return 0;
}