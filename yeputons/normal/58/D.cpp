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

char d;
bool cmp(const string &a, const string &b) { return a + d < b + d; }

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<string> ns;
    int w = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      ns.pb(buf); w += strlen(buf);
    }
    scanf(" %c", &d);
    sort(ns.begin(), ns.end(), cmp);
    w /= (n / 2);

    vi rem(11, 0);
    for (int i = 0; i < n; i++)
      rem.at(ns[i].length())++;

    vb was(n, false);
    for (int y = 0; y < (n / 2); y++) {
      string cur = "";
      for (int i = 0; i < n; i++) if (!was[i] && rem.at(w - ns[i].length())) {
        was[i] = true; rem.at(ns[i].length())--;
        cur += ns[i] + d;

        for (int i2 = 0; i2 < n; i2++) if (!was[i2] && ns[i2].length() == w - ns[i].length()) {
          was[i2] = true; rem.at(ns[i2].length())--;
          cur += ns[i2];
          break;
        }
        break;
      }
      printf("%s\n", cur.c_str());
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}