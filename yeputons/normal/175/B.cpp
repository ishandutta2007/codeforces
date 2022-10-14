#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

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
    map<string, int> vals;
    for (int i = 0; i < n; i++) {
      char buf[16];
      int x;
      scanf("%s%d", buf, &x);
      vals[buf] = max(vals[buf], x);
    }

    n = sz(vals);

    vector<string> ns(n);
    vi as(n);
    {
      int i = 0;
      for (map<string, int>::iterator it = vals.begin(); it != vals.end(); it++, i++) {
        ns[i] = it->first;
        as[i] = it->second;
      }
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      int bcnt = 0;
      for (int i2 = 0; i2 < n; i2++)
        if (as[i2] > as[i]) bcnt++;

      string res = "";
      if (bcnt * 100 > 50 * n) res = "noob";
      else if (bcnt * 100 > 20 * n) res = "random";
      else if (bcnt * 100 > 10 * n) res = "average";
      else if (bcnt * 100 > 1  * n) res = "hardcore";
      else res = "pro";
      printf("%s %s\n", ns[i].c_str(), res.c_str());
    }
  }
  return 0;
}