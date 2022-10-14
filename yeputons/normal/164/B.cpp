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

const int MAXL = 2e6 + 1e3;
const int MAXV = 1e6 + 1e3;
int as[2 * MAXL];
int bs[2 * MAXL];

int pos2[MAXV + 1];

int l1, l2;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &l1, &l2) >= 1) {
    for (int i = 0; i < l1; i++)
      scanf("%d", &as[i]), as[l1 + i] = as[i];

    memset(pos2, -1, sizeof pos2);
    for (int i = 0; i < l2; i++) {
      scanf("%d", &bs[i]), bs[l2 + i] = bs[i];
      pos2[bs[i]] = i;
    }

    int ans = 0;
    int p1 = -1, p2 = -1;

    int en = 0;
    for (int st = 0; st < l1; st++) {
      if (en < st) en = st;

      while (en < l1 + st) {
        int npos = pos2[as[en]];
        if (npos < 0) break;

        if (p1 >= 0) {
          if (p1 <= p2) {
            if (p1 <= npos && npos <= p2) break;
          } else {
            if (npos <= p2 || p1 <= npos) break;
          }
        }
        
        if (p1 < 0) p1 = npos;
        p2 = npos;

        en++;
      }
      ans = max(ans, en - st);
      if (st < en) {
        if (st + 1 < en) {
          p1 = pos2[as[st + 1]];
        } else {
          p1 = p2 = -1;
        }
      }
    }
    printf("%d\n", ans);
    break;
  }
  return 0;
}