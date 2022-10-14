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
    vi as;
    int bcnt = 0;

    for (int i = 0; i < 2 * n - 1; i++) {
      int x;
      scanf("%d", &x);
      as.pb(abs(x));
      if (x < 0) bcnt++;
    }

    int sum = accumulate(as.begin(), as.end(), 0);
    if (n % 2 == 1 || bcnt % 2 == 0) {
    } else {
      sort(as.begin(), as.end());
      sum -= 2 * as[0];
    }
    printf("%d\n", sum);
  }
  return 0;
}