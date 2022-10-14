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

int n;
vi as;
vb getseq(int ai, int bi) {
  int cv = as[ai], d = as[bi] - as[ai];
  vb g(n, false);

  cv = as[bi];
  for (int i = bi; i < n; i++)
    if (as[i] == cv) {
      g[i] = true;
      cv += d;
    }
  cv = as[ai];
  for (int i = ai; i >= 0; i--)
    if (as[i] == cv) {
      g[i] = true;
      cv -= d;
    }
  return g;
}

bool check_simple(const vb &g, const vb &g2) {
  for (int i = 0; i < n; i++)
    if (g[i] == g2[i]) return false;
  for (int i = 0; i < n; i++)
    if (g[i])
      printf("%d ", as[i]);
  printf("\n");
  for (int i = 0; i < n; i++)
    if (g2[i])
      printf("%d ", as[i]);
  printf("\n");
  return true;
}

bool check(int ai, int bi) {
  vb g = getseq(ai, bi);

  int nai = -1, nbi = -1;
  for (int i = 0; i < n; i++)
    if (!g[i]) {
      if (nai < 0) nai = i;
      else if (nbi < 0) nbi = i;
    }
  if (nai < 0) return false;

  if (nbi < 0) {
    for (int i = 0; i < n; i++)
      if (g[i])
        printf("%d ", as[i]);
    printf("\n%d\n", as[nai]);
    return true;
  }

  vb g2 = getseq(nai, nbi);

  if (check_simple(g, g2)) return true;
  for (int i = 0; i < n; i++)
    if (!g[i] && !g2[i]) return false;

  int max1 = 0;
  for (int i = 0; i < n; i++)
    if (g[i] && !g2[i]) max1 = i;
  int min2 = n - 1;
  for (int i = n - 1; i >= 0; i--)
    if (!g[i] && g2[i]) min2 = i;


  for (int i = 0; i < n; i++)
    eprintf("%d %d\n", !!g[i], !!g2[i]);

  for (int i = 0; i <= max1; i++)
    if (g[i])
      g2[i] = false;
  for (int i = min2; i < n; i++)
    if (g2[i])
      g[i] = false;
  for (int i = 0; i < n; i++)
    if (g[i] && g2[i])
      g2[i] = false;
  return check_simple(g, g2);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    as = vi(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    if (n == 2) {
      printf("%d\n%d\n", as[0], as[1]);
    } else {
//      assert(check(0, 1));
      if (!check(1, 2))
        if (!check(0, 1))
          if (!check(0, 2))
            printf("No solution\n");
    }
//    break;
  }
  return 0;
}