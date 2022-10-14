#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
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

  ll n, m, k;
  while (scanf("%I64d%I64d%I64d", &n, &m, &k) >= 1) {
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &a[i]);

    if (n % 2 == 0) {
      printf("0\n");
    } else {
      ll ncnt = (n - 1) / 2 + 1;
      ll cnt = (m / ncnt) * k;
      for (int i = 0; i < n; i += 2)
        cnt = min(cnt, a[i]);
      printf("%I64d\n", cnt);
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}