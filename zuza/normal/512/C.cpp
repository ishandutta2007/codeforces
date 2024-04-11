#include <cassert>
#include <cstring>

#include <cstdio>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 234;

vector<int> bef[MAXN];
vector<int> aft[MAXN];

bool is_prime(int x) {
  if (x <= 1) return true;
  for (int i = 2; i*i <= x; ++i)
    if (x%i == 0)
      return false;
  return true;
}

int cookie = 123;
int bio[MAXN];
int dad[MAXN];

bool match(int x) {
  if (bio[x] == cookie) return false;
  bio[x] = cookie;
  for (int y : bef[x]) {
    if (dad[y] == -1 || match(dad[y])) {
      dad[y] = x;
      return true;
    }
  }
  return false;
}

void bad() {
  puts("Impossible");
  exit(0);
}

int color[MAXN];
void dfs(int x, int d) {
  if (color[x] == d) return;
  if (color[x] != -1) assert(false);
  color[x] = d;
  for (int y : bef[x])
    dfs(y, d^1);
}

void recon(int x, vector<int>& cyc) {
  bio[x] = cookie;
  cyc.push_back(x);

  for (int y : aft[x]) {
    if (bio[y] != cookie) {
      recon(y, cyc);
    }
  }
}

int main(void) {
  int n; scanf("%d", &n);

  static int A[MAXN];
  REP(i, n) scanf("%d", A+i);
  REP(a, n) REP(b, n) if (a != b && is_prime(A[a]+A[b])) {
    bef[a].push_back(b);
  }

  memset(color, -1, sizeof color);
  REP(i, n) if (color[i] == -1) dfs(i, 0);
  int cnts[2] = {0, 0};
  REP(i, n) ++cnts[ color[i] ];
  if (cnts[0] != cnts[1]) bad();

  REP(step, 2) {
    memset(dad, -1, sizeof dad);
    memset(bio, -1, sizeof bio);
    REP(i, n) if (color[i] == 0) {
      ++cookie;
      if (!match(i)) bad();
    }

    REP(i, n) if (color[i] == 1) {
      int a = dad[i], b = i;
      aft[a].push_back(b);
      aft[b].push_back(a);

      auto it = find(bef[a].begin(), bef[a].end(), b);
      assert(it != bef[a].end());
      bef[a].erase(it);
    }
  }
  
  vector< vector<int> > out;
  ++cookie;
  REP(i, n) if (bio[i] != cookie) {
    vector<int> cyc;
    recon(i, cyc);
    out.push_back(cyc);
  }

  int sz = out.size();
  printf("%d\n", sz);
  REP(i, sz) {
    int k = out[i].size();
    printf("%d ", k);
    REP(j, k) printf("%d%c", out[i][j]+1, j+1 == k ? '\n' : ' ');
  }

  return 0;
}