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

bool get(ll a, ll b) {
  if (a > b) swap(a, b);
  assert(0 <= a && a <= b);
  if (a == 0) return false;

  if (!get(b % a, a)) return true;
  /*
  if (a % 2 == 1){ 
    for (int i = 1; i <= n; i++)
      assert(g[i] == (i % 2 == 0));
  }else {
    for (int i = 1; i <= n; i++) {
      int x = i % (a + 1);
      assert(g[i] == (x == a || x % 2 == 0));
    }
  }
  */
  ll x = b / a;
  if (a % 2 == 1) {
    return x % 2 == 0;
  } else {
    ll y = x % (a + 1);
    return y  == a || y % 2 == 0;
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) {
      ll a, b;
      scanf("%I64d%I64d", &a, &b);
      printf(get(a, b) ? "First\n" : "Second\n");
    }
  }
  return 0;
}