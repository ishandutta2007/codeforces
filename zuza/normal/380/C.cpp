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

const int MAXQ = 1e5 + 123;
const int MAXLEN = 1e6 + 123;

int ans[MAXQ];

struct Q {
  int l, r, idx;
};

vector<Q> E[MAXLEN];

struct Tournament {
  int n, offset;
  vector<int> data;

  Tournament(int n) : n(n) {
    offset = 2; while (offset < n) offset *= 2;
    data.resize(2*offset, 0);
  }

  void update(int pos, int delta) {
    for (int x = offset + pos; x; x /= 2)
      data[x] += delta;
  }

  int query(int l, int r) { // [l, r)
    int suma = 0;
    for (l += offset, r += offset; l < r; ++l>>=1, r>>=1) {
      if (l&1) suma += data[l];
      if (r&1) suma += data[r-1];
    }
    return suma;
  }
};

int main(void)
{
  static char inp[MAXLEN];
  memset(ans, -1, sizeof ans);

  scanf("%s", inp);
  int n_q; scanf("%d", &n_q);

  REP(i_q, n_q) {
    int l, r; scanf("%d %d", &l, &r); --l, --r;
    E[r].push_back({l, r, i_q});
  }

  int len = strlen(inp);
  vector<int> open; open.reserve(len);

  Tournament T(len);

  REP(i, len) {
    if (inp[i] == '(') open.push_back(i);
    else { // ')'
      if (open.empty()) {
      } else {
        int back = open.back();
        open.pop_back();
        T.update(back, 2);
      }
    }

    for (Q q : E[i]) {
      ans[q.idx] = T.query(q.l, i+1);
    }
  }

  REP(i_q, n_q) printf("%d\n", ans[i_q]);
  return 0;
}