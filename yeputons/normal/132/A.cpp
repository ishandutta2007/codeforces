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

int rev(int x) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    res = res * 2 + x % 2;
    x /= 2;
  }
  return res;
}

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    buf[0] = 0;
    fgets(buf, sizeof buf, stdin);
    int l = strlen(buf);
    while (l && strchr("\n\r", buf[l - 1]))
      buf[--l] = 0;
    if (!l) break;

    int pr = 0;
    for (int i = 0; i < l; i++) {
      int x = (rev(pr) - rev(buf[i])) & 0xFF;
      printf("%d\n", x);
      pr = buf[i];
    }
  }
  return 0;
}