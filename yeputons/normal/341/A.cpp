#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    sort(as.begin(), as.end());

    ll suml = 0, sumr = 0;
    for (int i = 0; i < n; i++) sumr += as[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      sumr -= as[i];

      ll sumLen = 0;
      sumLen += sumr - ll(n - i - 1) * as[i];
      sumLen += ll(i) * as[i] - suml;
//      eprintf("%I64d (%I64d %I64d)\n", sumLen, suml, sumr);
      ans += sumLen;

      suml += as[i];
    }
//    eprintf("%I64d %I64d\n", ans, ansb);
    for (int i = 0; i < n; i++)
      ans += as[i];
    ll ansb = n;
    ll x = gcd(ans, ansb);
    ans /= x;
    ansb /= x;
    printf("%I64d %I64d\n", ans, ansb);
  }
  return 0;
}