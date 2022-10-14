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
  #endif

  ll k, b; int n; ll t;
  while (scanf("%I64d%I64d%d%I64d", &k, &b, &n, &t) >= 1) {
    int ans = n;
    ll cur = 1;
    while (cur < t && ans > 0) {
      cur = cur * k + b;
      ans--;
    }
    if (cur > t) ans++;
    printf("%d\n", ans);
  }
  return 0;
}