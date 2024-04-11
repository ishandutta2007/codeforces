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

char buf[1000];

struct Node {
  int ne[26];
  int ecnt;
  Node() { memset(ne, -1, sizeof ne); ecnt = 0; }
  int& operator[](int x) { return ne[x]; }
};

const int INF = 2e9 + 2e6;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      ss[i] = buf;
    }
    sort(ss.begin(), ss.end());

    vi lcp0(n - 1);
    for (int i = 0; i + 1 < n; i++) {
      int k = 0;
      while (ss[i][k] && ss[i][k] == ss[i + 1][k]) k++;
      lcp0[i] = k;
    }

    vvi lcp(n, vi(n, 0));
    for (int a = 0; a + 1 < n; a++) {
      int k = lcp0[a];
      for (int b = a + 1; b < n; b++) {
        k = min(k, lcp0[b - 1]);
        lcp[a][b] = lcp[b][a] = k;
      }
    }

    vector<Node> ns(1);
    for (int i = 0; i < n; i++) {
      int v = 0;
      for (int i2 = 0; ss[i][i2]; i2++) {
        int c = ss[i][i2] - 'a';

        if (ns[v][c] < 0) {
          ns.pb(Node());
          ns[v][c] = sz(ns) -1;
        }
        v = ns[v][c];
      }
      ns[v].ecnt++;
    }

    vvi dyn(sz(ns), vi(k + 1, -INF));
    for (int v = sz(ns) - 1; v >= 0; v--) {
      vvi dc(27, vi(k + 1, -INF));
      for (int ccnt = 0; ccnt <= ns[v].ecnt; ccnt++)
        dc[0][ccnt] = 0;

      for (int i = 0; i < 26; i++) {
        int b = ns[v][i];
        if (b < 0) {
          dc[i + 1] = dc[i];
          continue;
        }
        assert(v <= b);
        for (int wcnt = 0; wcnt <= k; wcnt++) if (dc[i][wcnt] >= 0)
        for (int ccnt = 0; wcnt + ccnt <= k; ccnt++) {
          dc[i + 1][wcnt + ccnt] = max(dc[i + 1][wcnt + ccnt], dc[i][wcnt] + dyn[b][ccnt]);
        }
      }
      for (int ccnt = 0; ccnt <= k; ccnt++)
        if (dc[26][ccnt] >= 0) {
          dyn[v][ccnt] = dc[26][ccnt] + ccnt * (ccnt - 1) / 2;
        }
    }
    printf("%d\n", dyn[0][k] - k * (k - 1) / 2);
  }
  return 0;
}