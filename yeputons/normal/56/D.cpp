#include <cstdio>
#include <cstdlib>
#include <cstdarg>
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

void relax(int &a1, int &a2, int b1, int b2) {
  if (a1 > b1) {
    a1 = b1;
    a2 = b2;
  }
}

const int MAXL = 1000;

char s1[MAXL + 1];
char s2[MAXL + 1];
int d[MAXL + 1][MAXL + 1];
int fr[MAXL + 1][MAXL +  1];
int to[MAXL + 1][MAXL +  1];

char buf[1024];

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%s%s", s1, s2) >= 2) {
    memset(d, 0x3F, sizeof d);
    memset(fr, -1, sizeof fr);
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    d[0][0] = 0;
    for (int a = 0; a <= l1; a++)
      for (int b = 0; b <= l2; b++) {
        int v = d[a][b];

        if (a < l1 && b < l2) {
          relax(d[a + 1][b + 1], fr[a + 1][b + 1], v + (s1[a] != s2[b]), 0);
        }
        if (a < l1)
          relax(d[a + 1][b], fr[a + 1][b], v + 1, 1);
        if (b < l2)
          relax(d[a][b + 1], fr[a][b + 1], v + 1, 2);
      }

    vector<string> ops;
    {
      memset(to, -1, sizeof to);

      int a = l1, b = l2;
      while (fr[a][b] >= 0) {
        switch (fr[a][b]) {
        case 0: a--, b--;
          to[a][b] = 0;
          break;
        case 1: a--;
          to[a][b] = 1;
          break;
        case 2: b--;
          to[a][b] = 2;
          break;
        }
      }

      a = 0, b = 0;

      while (a < l1 || b < l2) {
        buf[0] = 0;
        switch (to[a][b]) {
        case 0:
          if (s1[a] != s2[b])
            snprintf(buf, sizeof buf, "REPLACE %d %c", b + 1, s2[b]);
          a++, b++;
          break;
        case 1:
          snprintf(buf, sizeof buf, "DELETE %d", b + 1);
          a++;
          break;
        case 2:
          snprintf(buf, sizeof buf, "INSERT %d %c", b + 1, s2[b]);
          b++;
          break;
        }

        if (buf[0]) ops.pb(buf);
      }
    }

    assert(ops.size() == d[l1][l2]);
    printf("%d\n", d[l1][l2]);
    for (int i = 0; i < ops.size(); i++)
      printf("%s\n", ops[i].c_str());

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}