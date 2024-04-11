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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int ans = 0;
    for (;;) {
      int p = n - 1;
      bool found = false;
      for (int i = k - 1; i >= 1; i--) {
        while (p >= 0 && a[p] > i) p--;
        if (p >= 0 && a[p] == i) { a[p]++; found = true; }
      }
      if (!found) break;
      ans++;
    }
    printf("%d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}