#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
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

char s1[(int)1e4 + 1];
char s2[(int)1e6 + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", s1, s2) >= 2) {
    vi fir(256, -1);
    for (int i = 0; s1[i]; i++)
      if (fir[s1[i]] < 0)
        fir[s1[i]] = i;

    int l1 = strlen(s1);
    vvi ne(l1, vi(256, -1));
    vi last(256, -1);
    for (int i = l1 - 1; i >= 0; i--) {
      ne[i] = last;
      last[s1[i]] = i;
    }

    try {
      int p = fir[s2[0]], ans = 1;
      for (int i = 0;;) {
        if (p < 0) throw 0;
        
        i++;
        if (!s2[i]) break;

        p = ne[p][s2[i]];
        if (p < 0) {
          ans++;
          p = fir[s2[i]];
        }
      }
      printf("%d\n", ans);
    } catch (...) {
      printf("-1\n");
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}