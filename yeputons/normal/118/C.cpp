#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

const int MAXL = 1e4;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, k;
  while (scanf("%d%d%s", &n, &k, s) >= 3) {
    int ans = 1e9;
    string res = "botva";
    for (int dig = 0; dig < 10; dig++) {
      int ccnt = 0;
      int cans = 0;
      string cres = s;
      for (int df = 0; df < 10; df++) {
        char nval = dig + df + '0';
        for (int i = 0; i < n; i++) if (s[i] == nval && ccnt < k) {
          cres[i] = '0' + dig;
          ccnt++;
          cans += df;
        }
        if (df) {
          nval = dig - df + '0';
          for (int i = n - 1; i >= 0; i--) if (s[i] == nval && ccnt < k) {
            cres[i] = '0' + dig;
            ccnt++;
            cans += df;
          }
        }
      }
      if (cans < ans || (cans == ans && cres < res)) {
        ans = cans;
        res = cres;
      }
    }
    printf("%d\n%s\n", ans, res.c_str());
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}