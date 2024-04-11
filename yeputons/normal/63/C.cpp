#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool check(int x) {
  vb was(10);
  for (int i = 0; i < 4; i++, x /= 10) {
    if (was[x % 10]) return false;
    was[x % 10] = true;
  }
  return true;
}
void get(int x, int n, int &a, int &b) {
  a = b = 0;
  vb was1(10), was2(10);
  for (int i = 0; i < 4; i++, x /= 10, n /= 10) {
    if (x % 10 == n % 10) a++;
    was1[x % 10] = true, was2[n % 10] = true;
  }
  for (int i = 0; i < 10; i++)
    if (was1[i] && was2[i]) b++;
  b = b - a;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    vi ns(n), as(n), bs(n);
    for (int i = 0; i < n; i++) scanf("%d%d%d", &ns[i], &as[i], &bs[i]);

    int cnt = 0, ans = -1;
    for (int i = 0; i < 10000; i++) if (check(i)) {
      bool g = true;
      for (int i2 = 0; i2 < n; i2++) {
        int a, b;
        get(i, ns[i2], a, b);
        if (a != as[i2] || b != bs[i2]) { g = false; break; }
      }
      if (g) ans = i;
      cnt += g;
    }
    if (cnt > 1) printf("Need more data\n");
    else if (cnt == 1) printf("%04d\n", ans);
    else printf("Incorrect data\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}