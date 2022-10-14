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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w, k, t;
  while (scanf("%d%d%d%d", &h, &w, &k, &t) >= 4) {
    vector<pii> bad(k);
    for (int i = 0; i < k; i++)
      scanf("%d%d", &bad[i].first, &bad[i].second);
    sort(bad.begin(), bad.end());

    for (int i = 0; i < t; i++) {
      pii cur;
      scanf("%d%d", &cur.first, &cur.second);
      int cnt = lower_bound(bad.begin(), bad.end(), cur) - bad.begin();

      if (cnt < bad.size() && bad[cnt] == cur) {
        printf("Waste\n");
      } else {
        cur.first--, cur.second--;
        cnt = cur.first * w + cur.second - cnt;
        const char *names[3] = { "Carrots", "Kiwis", "Grapes" };
        printf("%s\n", names[cnt % 3]);
      }
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}