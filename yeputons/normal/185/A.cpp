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

const int MOD = 1000000007;
int sum(int a, int b) { return (ll(a) + b) % MOD; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int pow(int a, ll b) {
  int res = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1)
      res = mul(res, a);
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll n;
  while (scanf("%I64d", &n) >= 1) {
    if (n == 0) {
      printf("1\n");
    } else {
      printf("%d\n", sum(pow(2, 2 * n - 1), pow(2, n - 1)));
    }
  }
  return 0;
}