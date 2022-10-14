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

  int n;
  while (scanf("%d", &n) >= 1) {
    map<int, int> cnts;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (x > 0)
        cnts[x]++;
    }
    bool g = true;
    int ans = 0;
    for (map<int, int>::iterator it = cnts.begin(); it != cnts.end(); it++)
      if (it->second > 2) g = false;
      else if (it->second == 2) ans++;
    if (!g) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}