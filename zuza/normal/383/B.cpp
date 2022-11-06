#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 1e5 + 123;

struct S {
  int ind;
  int pos;
  friend bool operator < (const S& a, const S& b) {
    return a.pos < b.pos;
  }
};

int dim, n_v;
int bio[MAXN];

int Xs[MAXN];
int Ys[MAXN];

map<int, vector<S> > row_v, col_v;

int main(void)
{
  scanf("%d %d", &dim, &n_v);
  auto push = [&](int i, int x, int y) {
    Xs[i] = x;
    Ys[i] = y;
    row_v[x].push_back({i, -y});
    col_v[y].push_back({i, x});
  };
  REP(i, n_v) {
    int x, y; scanf("%d %d", &x, &y);
    push(i, x, y);
  }

  for (auto& p : row_v) sort(p.second.begin(), p.second.end());
  for (auto& p : col_v) sort(p.second.begin(), p.second.end());

  queue<int> Q;

  REP(i, n_v) {
    if (Xs[i] == dim && !bio[i]) {
      bio[i] = true;
      Q.push(i);
    }
    if (Ys[i] == 1 && !bio[i]) {
      bio[i] = true;
      Q.push(i);
    }
  }

  auto sredi = [&](vector<S> &v, int pos) {
    while (!v.empty() && v.back().pos >= pos) {
      int ind = v.back().ind;
      if (!bio[ind]) {
        bio[ind] = true;
        Q.push(ind);
      }
      v.pop_back();
    }
  };

  bool ok = true;
  for (; !Q.empty(); Q.pop()) {
    int ind = Q.front();
    if (Xs[ind] == 1 || Ys[ind] == dim) ok = false;
    int x = Xs[ind], y = Ys[ind];
    sredi(row_v[x-1], -(y+1));
    sredi(col_v[y+1], x-1);   
  }


  if (ok)
    printf("%d\n", 2*dim - 2);
  else
    printf("-1\n");
  return 0;
}