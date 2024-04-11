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

const int MAXL = 2100;
char s[MAXL + 1];
char t[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", s, t) >= 1) {
    int l1 = strlen(s), l2 = strlen(t);

    int ans = l2;
    for (int st = -l2; st < l1; st++) {
      int cans = 0;
      for (int i = 0; i < l2; i++) {
        int pos = st + i;
        if (pos < 0 || pos >= l1) {
          cans++;
          continue;
        }
        cans += s[pos] != t[i];
      }
      ans = min(ans, cans);
    }
    printf("%d\n", ans);
  }
  return 0;
}