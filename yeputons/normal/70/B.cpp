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

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

bool isEnd(char c) { return c == '.' || c == '?' || c == '!'; }

const int INF = 1e9;

char buf[(int)1e5];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int sz;
  while (scanf("%d", &sz) >= 1) {
    vi seqs;
    string cur = "";
    for (;;) {
      if (scanf("%s", buf) < 1) {
        #ifdef DEBUG
        assert(!cur.length());
        #endif
        break;
      }
      if (cur.length())
        cur += " ";
      cur += buf;
      if (isEnd(buf[strlen(buf) - 1])) {
        seqs.pb(cur.length());
        cur = "";
      }
    }

    int n = seqs.size();
    vi sums(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + seqs[i];
      eprintf("%d\n", seqs[i]);
    }

    vi ans(n + 1, INF);

    ans[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int pr = 0; pr <= i; pr++) {
        if (sums[i + 1] - sums[pr] + (i - pr) <= sz) {
          ans[i + 1] = min(ans[i + 1], ans[pr] + 1);
        }
      }
    }

    if (ans[n] >= INF)
      printf("Impossible\n");
    else
      printf("%d\n", ans[n]);

    break;
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}