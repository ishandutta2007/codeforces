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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    reverse(as.begin(), as.end());

    vector<pii> bs(n);
    for (int i = 0; i < n; i++)
      bs[i] = mp(as[i], -i);
    sort(bs.begin(), bs.end());

    vi res(n, -1);
    int mpos = n;

    for (int i = 0; i < n; i++) {
      int x = -bs[i].second;
      if (mpos < x)
        res[x] = x - mpos - 1;
      else
        mpos = x;
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < n; i++)
      printf("%d%c", res[i], "\n "[i + 1 < n]);
  }
  return 0;
}