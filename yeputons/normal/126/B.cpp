#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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

const int MAXL = 1e6;
char s[MAXL + 100];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int l = strlen(s);
    bool g = false;
    vi p(l, 0);
    for (int i = 1; i < l; i++) {
      int k = p[i - 1];
      while (s[k] != s[i] && k > 0)
        k = p[k - 1];
      if (s[k] == s[i])
        k++;
      p[i] = k;
    }

    vb vals(l + 1, false);
    for (int i = 1; i < l - 1; i++)
      vals[p[i]] = true;
    int al = p[l - 1];
    while (al > 0) {
      if (vals[al]) break;
      al = p[al - 1];
    }

    if (al > 0) {
      s[al] = 0;
      printf("%s\n", s);
      g = true;
    }
    if (!g)
      printf("Just a legend\n");
  }
  return 0;
}