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

const char *ds = "47";
const int MAXL = 100000;
char buf[MAXL + 1];
int ceq[2][MAXL + 1];

bool check(int pos, int c1, int c2) {
  if (ceq[1][pos] > c1) return false;
  if (ceq[1][pos] < c1) return buf[pos + ceq[1][pos]] < ds[1];
  pos += c1;
  assert(ceq[0][pos] <= c2);
  if (ceq[0][pos] < c2) return buf[pos + ceq[0][pos]] < ds[0];
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", buf) >= 1) {
    int l = strlen(buf);

    memset(ceq, 0, sizeof ceq);
    for (int dig = 0; dig < 2; dig++) {
      for (int i = l - 1; i >= 0; i--)
        ceq[dig][i] = (buf[i] == ds[dig]) ? ceq[dig][i + 1] + 1 : 0;
    }

    string ans = "???";
    for (int d = 0; d <= 2; d++) if ((l + d) % 2 == 0) {
      if (d) {
        ans = "";
        l = l + d;
        for (int i = 0; i < l / 2; i++) ans += "4";
        for (int i = 0; i < l / 2; i++) ans += "7";
        break;
      }

      ans = "";
      if (!check(0, l / 2, l / 2)) continue;

      const char *ds = "47";
      int ws[] = { l / 2, l / 2 };

      bool grea = false;
      ans = "";
      for (int i = 0; i < l; i++) {
        bool found = false;
        for (int dig = 0; dig < 2; dig++) {
          if (ws[dig] <= 0) continue;
          if (!grea && (buf[i] > ds[dig])) continue;
          if (!grea && buf[i] == ds[dig])
            if (!check(i + 1, ws[1] - (dig == 1), ws[0] - (dig == 0))) continue;
          ws[dig]--;
          ans += ds[dig];
          if (buf[i] < ds[dig]) grea = true;
          found = true;
          break;
        }
        assert(found);
      }
      break;
    }
    printf("%s\n", ans.c_str());

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}