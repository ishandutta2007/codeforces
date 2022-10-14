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

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n, k, c;
  while (scanf("%d%d%d", &n, &k, &c) >= 3) {
    vi x(c + 1);
    x[0] = 0;
    for (int i = 0; i < c; i++) scanf("%d", &x[i + 1]);
    x.pb(n + 1);

    int ans = 0;
    for (int i = 0; i + 1 < x.size(); i++) {
      ans++;
      for (int p = x[i] + k; p < x[i + 1]; p += k)
        ans++;
    }
    printf("%d\n", ans - 1);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}