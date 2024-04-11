#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

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

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    vi degs(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      degs[a]++;
      degs[b]++;
    }
    
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
      if (degs[i] == 1) c1++;
      else if (degs[i] == 2) c2++;

    if (c2 == n) {
      printf("ring topology\n");
    } else if (c1 == n - 1) {
      printf("star topology\n");
    } else if (c1 == 2 && c2 == n - 2) {
      printf("bus topology\n");
    } else {
      printf("unknown topology\n");
    }
  }
  return 0;
}