#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXL = 110;
char s[MAXL + 1];

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    if (n <= 2) {
      printf("1\n");
      continue;
    }

    ll ans = 0;
    for (int type = 0; type < 2; type++)
    for (int fir = 0; fir < 2; fir++) {
      vector<vll> dyn(n + 1, vll(2, 0));
      if (type == 1) {
        if (fir == 0) continue;
        if (s[0] != 'A' || s[n - 1] != 'B') continue;
        dyn[1][1] = 1;
      } else {
        if (s[0] == 'A') {
          if (fir == 0)
            dyn[1][0] = 1;
        } else {
          if (fir == 1)
            dyn[1][1] = 1;
          else if (s[1] == 'A')
            dyn[2][1] = 1;
        }
      }

      for (int i = 1; i < n; i++)
      for (int pr = 0; pr < 2; pr++) {
        if (!dyn[i][pr]) continue;

        int cc = s[i] - 'A';
//        eprintf("i=%d, pr=%d, cc=%d\n", i, pr, cc);
        if (cc == 0) {
          dyn[i + 1][0] += dyn[i][pr];
        } else {
          if (pr == 1)
            dyn[i + 1][1] += dyn[i][pr];

          int ne = i + 1; if (ne >= n) ne -= n;
          int cc2 = s[ne] - 'A';
          if (cc2 == 0 && (i + 1 < n || type))
            dyn[min(i + 2, n)][i + 1 >= n ? 0 : 1] += dyn[i][pr];
        }
      }
      if (type == 0) {
        ans += dyn[n][1];
        if (fir == 0) ans += dyn[n][0];
      } else
        ans += dyn[n][0];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}