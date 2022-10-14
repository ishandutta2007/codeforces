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
    vb was(n, false);
    int cur = 0;
    for (int i = 0; i < n * (n + 1); i++) {
      was[cur] = true;
      cur += i + 1;
      cur %= n;
    }
    bool g = true;
    for (int i = 0; i < n; i++) if (!was[i]) g = false;
    printf(g ? "YES\n" : "NO\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}