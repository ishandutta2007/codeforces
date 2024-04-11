#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
void madd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<vi> dyn(n + 1, vi(2, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int cur = 0; cur < 2; cur++) {
        dyn[i][cur] = dyn[i + 1][cur];
        if (cur == (i & 1)) {
          madd(dyn[i][cur], dyn[i + 1][!cur]);
          madd(dyn[i][cur], 1);
        }
      }
    }
    int res = 0;
    madd(res, dyn[0][0]);
    madd(res, dyn[0][1]);
    printf("%d\n", res);
  }
  return 0;
}