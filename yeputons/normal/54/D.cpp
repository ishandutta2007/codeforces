#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<string> vs;

char t[101];
int p[100];
int l;

void calcp() {
  l = strlen(t);
  p[0] = 0;
  for (int i = 1; i < l; i++) {
    int k = p[i - 1];
    while (t[i] != t[k] && k)
      k = p[k - 1];

    p[i] = 0;
    if (t[i] == t[k])
      p[i] = k + 1;
  }
}

int getM(int m, char c) {
  assert(0 <= m && m < l);
  while (t[m] != c && m)
    m = p[m - 1];
  if (t[m] == c) return m + 1;
  return 0;
}

char mat[101];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 2) {
    scanf("%s%s", t, mat);
    calcp();
    vector<vs> d(n + 1, vs(l, ""));
    vector<vb> ca(n + 1, vb(l, false));
    ca[0][0] = true;
    for (int i = 0; i < n; i++)
      for (int m = 0; m < l; m++) if (ca[i][m]) {
//        eprintf("ca[%d][%d]\n", i, m);

        for (char c = 'a'; c < 'a' + k; c++) {
          int nm = getM(m, c);
//          eprintf("  +%c --> %d\n", c, nm);

          int pos = i - l + 1;
          if (pos >= 0) {
            if (mat[pos] - '0' != (nm == l))
              continue;
          }
          if (nm == l) {
            assert(pos >= 0);
            nm = p[nm - 1];
          }
          if (!ca[i + 1][nm]) {
            ca[i + 1][nm] = true;
            d[i + 1][nm] = d[i][m] + string(1, c);
          }
        }
      }

    bool g = false;
    for (int i = 0; i < l; i++)
      if (ca[n][i]) {
        g = true;
        printf("%s\n", d[n][i].c_str());
        break;
      }
    if (!g) printf("No solution\n");

    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}