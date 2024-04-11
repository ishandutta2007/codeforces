#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 3e5 + 123;

int dad[MAXN];
int kol[MAXN];

int find_dad(int x) {
  if (dad[x] == -1) return x;
  return dad[x] = find_dad(dad[x]);
}

int biggest = 0; // !?  n=1?

void merge(int a, int b) {
  a = find_dad(a);
  b = find_dad(b);

  if (a > b) swap(a, b);
  kol[a] += kol[b];
  biggest = max(biggest, kol[a]);
  dad[b] = a;
}

int main(void) {
  memset(dad, -1, sizeof dad);
  memset(kol, 0, sizeof kol);

  struct SS {
    int val, idx;
  };
  vector<SS> ss;

  int n; scanf("%d", &n);
  REP(i, n) {
    int x; scanf("%d", &x);
    ss.push_back({x, i});
  }
  sort(ss.begin(), ss.end(), [](SS a, SS b) { return a.val > b.val; });

  vector<int> out(n+1, -1);
  for (auto s : ss) {
    int idx = s.idx;
    kol[idx] = 1; biggest = max(biggest, 1);
    
    if (idx-1 >= 0 && kol[idx-1] > 0) {
      merge(idx, idx-1);
    }
    if (idx+1 < n && kol[idx+1] > 0) {
      merge(idx, idx+1);
    }
    //    TRACE(s.idx _ s.val _ biggest);
    if (out[biggest] == -1) out[biggest] = s.val;
  }

  vector<int> real(n+1);

  int maks = -1;
  for (int i = n; i > 0; --i) {
    maks = max(maks, out[i]);
    real[i] = maks;
  }

  FOR(i, 1, n+1)
    printf("%d%c", real[i], i+1 == n+1 ? '\n' : ' ');

  return 0;
}