#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int maxk;
vvi es;
ll ans;

const int MAXN = 50000;
const int MAXK = 500;
int mem[MAXN][MAXK + 1];
void calc(int v, int par = -1) {
  mem[v][0]++;

  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;
    calc(b, v);

    for (int l = 1; l <= maxk; l++) {
      int l2 = maxk - l;
      ans += ll(mem[v][l2]) * mem[b][l - 1];
    }
    for (int l = 1; l <= maxk; l++)
      mem[v][l] += mem[b][l - 1];
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d", &n, &maxk) >= 1) {
    es = vvi(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    ans = 0;
    memset(mem, 0, sizeof mem);
    calc(0);
    printf("%I64d\n", ans);
  }
  return 0;
}