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
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int MAXW = 1000;
const int MAXK = 1000;

int mul(int a, int b) {
  return ll(a) * ll(b) % MOD;
}
void add(int &a, int b) {
  a += b;
  if (a >= MOD) 
    a -= MOD;
}

int d[MAXW + 1][MAXK + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (int cw = 1; cw <= MAXW; cw++)
    d[cw][0] = 1;

  for (int ck = 1; ck <= MAXK; ck++) {
    int cval = 0;
    int csum = 0;
    for (int cw = 1; cw <= MAXW; cw++) {
      if (cw - 2 >= 0) {
        add(cval, csum);
        add(cval, d[cw - 2][ck - 1]);
        add(csum, d[cw - 2][ck - 1]);
      }
      d[cw][ck] = cval;
    }
  }

  int w, h, k;
  while (scanf("%d%d%d", &w, &h, &k) >= 3) {
    printf("%d\n", mul(d[w][k], d[h][k]));
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}