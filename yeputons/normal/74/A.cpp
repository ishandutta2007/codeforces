#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <map>
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

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    pair<int, string> ans((int)-1e9, "");
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      int a, b;
      scanf("%d%d", &a, &b);
      int cnt = a * 100 - b * 50;
      for (int i2 = 0; i2 < 5; i2++) {
        int x;
        scanf("%d", &x);
        cnt += x;
      }
      ans = max(ans, mp(cnt, string(buf)));
    }
    printf("%s\n", ans.second.c_str());

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}