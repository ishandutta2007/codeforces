#include <cstdio>
#include <cstdlib>
#include <cstdarg>
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

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;

    bool g = false;
    for (int i = 0; i < n; i++) if (a[i] != i) {
      int al = i, ar = a[i];
      if (al < ar) {
        int l = al, r = ar;
        for (; l <= r; l++, r--) swap(a[l], a[r]);

        g = true;
        for (int i = 0; i < n; i++) g = g && (a[i] == i);
        if (g) printf("%d %d\n", al + 1, ar + 1);
      }
      break;
    }
    if (!g) printf("0 0\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}