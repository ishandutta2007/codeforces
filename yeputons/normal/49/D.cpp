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

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int n;
char buf[1001];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d %s", &n, buf) >= 1) {
    int a = n + 1;
    for (int step = 0; step < 2; step++) {
      int ca = 0;
      for (int i = 0; i < n; i++)
        ca += buf[i] - '0' != (step ^ (i & 1));
      a = min(a, ca);
    }
    printf("%d\n", a);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}