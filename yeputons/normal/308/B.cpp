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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXL = 1e7;
char _buf[MAXL + 1];

const int MAXN = 1e6 + 100;
const int K = 20;

int nes[MAXN + 1][K];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, h, w;
  while (scanf("%d%d%d", &n, &h, &w) >= 1) {
    vi ls(n);
    vector<char*> ss(n);
    {
      char *buf = _buf;
      for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        ls[i] = strlen(buf);
        ss[i] = buf;
        buf += ls[i] + 1;
      }
    }

    vi slens(n + 1);
    for (int i = 0; i < n; i++)
      slens[i + 1] = slens[i] + ls[i];

    for (int i = 0; i < K; i++)
      nes[n][i] = n;

    for (int i = n - 1; i >= 0; i--) {
      int cend = nes[i + 1][0];
      while (cend > i) {
        int clen = slens[cend] - slens[i] + (cend - i - 1);
        if (clen <= w) break;
        cend--;
      }
      nes[i][0] = cend;
      for (int i2 = 1; i2 < K; i2++)
        nes[i][i2] = nes[nes[i][i2 - 1]][i2 - 1];
    }

    int bans = -1;
    int bst = -1;
    for (int st = 0; st < n; st++) {
      int en = st;
      int rem = h;
      for (int i = K - 1; i >= 0; i--)
        if (rem >= (1 << i))
          rem -= 1 << i, en = nes[en][i];
      int cans = en - st;
      if (cans > bans) {
        bans = cans;
        bst = st;
      }
    }

    int ptr = bst;
    for (int y = 0; y < h; y++) {
      int a = ptr, b = nes[a][0];
      for (int i = a; i < b; i++) {
        if (i > a) printf(" ");
        printf("%s", ss[i]);
      }
      printf("\n");
      ptr = b;
    }
    #ifdef DEBUG
    printf("==========\n");
    #endif
  }
  return 0;
}