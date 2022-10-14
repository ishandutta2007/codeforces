#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
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

const int MAXL = 1e5 + 1e3;
char s[MAXL + 1];
char res[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    vector<pii> maxs(n + 1, mp(-1, n));
    for (int i = n - 1; i >= 0; i--)
      maxs[i] = max(maxs[i + 1], mp((int)s[i], -i));

    int rlen = 0;
    for (int i = 0; i < n; i++) {
      i = -maxs[i].second;
      res[rlen++] = s[i];
    }
    res[rlen] = 0;
    printf("%s\n", res);
  }
  return 0;
}