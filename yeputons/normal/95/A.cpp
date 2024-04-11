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

char low(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
  return c;
}
char cap(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
  return c;
}
char norm(char c, char reg) {
  eprintf("reg=%c; %d %d\n", reg, reg >= 'a', reg <= 'z');
  if (reg >= 'a' && reg <= 'z') return low(c);
  else return cap(c);
}

bool check(const char *s, const char *p) {
  for (int i = 0; p[i]; i++)
    if (low(s[i]) != low(p[i])) return false;
  return true;
}

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<string> sts(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      sts[i] = buf;
    }

    char lucky;
    scanf("%s %c", buf, &lucky);
    lucky = low(lucky);

    int l = strlen(buf);
    vb good(l, false);
    for (int i = 0; i < l; i++) {
      for (int i2 = 0; i2 < n; i2++)
        if (check(buf + i, sts[i2].c_str()))
          for (int i3 = 0; i3 < sts[i2].length(); i3++)
            good[i + i3] = true;
    }

    string res = "";
    for (int i = 0; i < l; i++)
      if (good[i]) {
        if (low(buf[i]) != lucky)
          res += norm(lucky, buf[i]);
        else
          for (int c = 'a'; c <= 'z'; c++) if (low(buf[i]) != c) {
            res += norm(c, buf[i]);
            break;
          }
      } else
        res += buf[i];
    printf("%s\n", res.c_str());

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}