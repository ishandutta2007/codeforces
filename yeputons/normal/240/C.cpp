#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    int k = 0;
    while ((1 << k) < n) k++;

    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
      vi xs;
      for (int i2 = 0; i2 < n; i2++)
        if (i2 & (1 << i)) xs.pb(i2);
      printf("%d", sz(xs));
      for (int i2 = 0; i2 < sz(xs); i2++)
        printf(" %d", xs[i2]);
      printf("\n");
    }
  }
  return 0;
}