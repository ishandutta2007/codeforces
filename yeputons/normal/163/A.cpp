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

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

const int MAXL = 5010;
char s[MAXL + 1];
char t[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", s, t) >= 2) {
    int l1 = strlen(s), l2 = strlen(t);
    vvi d(l1 + 1, vi(l2 + 1, 0));
    for (int i = 0; i <= l1; i++)
      d[i][l2] = 1;

    for (int a = l1; a >= 0; a--)
    for (int b = l2 - 1; b >= 0; b--) {
      add(d[a][b], d[a][b + 1]);
      if (a < l1 && s[a] == t[b]) {
        add(d[a][b], d[a + 1][b + 1]);
      }
    }
    int ans = 0;
    for (int st = 0; st < l1; st++) {
//      assert(d[st][0] > 0);
      add(ans, d[st][0] - 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}