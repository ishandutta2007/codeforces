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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int solved = 0, cntasks = 0;
vvi ans(1 << 8);

void answer(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

void ask(int x) {
  if (solved || !ans[x].empty()) {
    cerr << "fail\n";
    return;
  }
  ++cntasks;
  if (cntasks > 16) {
    answer(x);
    solved++;
    return;
  }
  //assert(cntasks <= 16);
  printf("? %d\n", x);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  vi v(k);
  for (int i = 0; i < k; ++i) scanf("%d", &v[i]);
  if (v.size() == 2) {
    answer(x);
    solved++;
  }
  ans[x] = v;
}

void run(vi & v) {
  while (!solved) {
    int cur = v.back();
    ask(cur);
    if (ans[cur].size() <= 2) break;
    for (int y : ans[cur]) {
      if (ans[y].empty()) {
        v.push_back(y);
        break;
      }
    }
  }
}

int main() {
  //  std::ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    for (int i = 0; i < ans.size(); ++i) ans[i].clear();
    solved = cntasks = 0;
    int n;
    scanf("%d", &n);
    int x = 1, h = 1;
    ask(x);
    if (ans[x].size() == 1) {
      h = 1; x = ans[x][0];
    } else {
      vi v1(1, ans[x][0]), v2(1, ans[x][1]);
      run(v1);
      run(v2);
      if (!solved) {
        vi v = v1;
        reverse(v.begin(), v.end());
        v.push_back(x);
        for (int y : v2) v.push_back(y);
        int c = v[v.size() / 2];
        for (int y : ans[c]) {
          if (ans[y].empty()) x = y;
        }
        h = v.size() / 2 + 1;
      }
    }
    while (!solved && h + 3 < n) {
      ask(x);
      vi v;
      for (int y : ans[x]) {
        if (ans[y].empty()) {
          v.push_back(y);
          break;
        }
      }
      if (!solved) assert(!v.empty());
      run(v);
      if (!solved) {
        reverse(v.begin(), v.end());
        for (int i = 0; i <= h; ++i) v.push_back(x);
        int c = v[v.size() / 2];
        for (int y : ans[c]) {
          if (ans[y].empty()) x = y;
        }
        h = v.size() / 2 + 1;
      }
    }
    vi q(1, x);
    int it = 0;
    while (!solved && it < q.size()) {
      ask(q[it]);
      for (int y : ans[q[it]]) {
        if (ans[y].empty()) q.push_back(y);
      }
      ++it;
    }
  }
  return 0;
}