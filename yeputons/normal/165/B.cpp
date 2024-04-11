#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define TASKNAME "std"
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int k;
ll calc(ll v) {
  ll res = 0;
  ll ck = 1;
  while (v / ck > 0) {
    res += v / ck;
    ck = ck * k;
  }
  return res;
}

int main()  {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d", &n, &k) >= 1) {
    int L = 0, R = n;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (calc(M) >= n) R = M;
      else L = M;
    }
    printf("%d\n", R);
  }
  return 0;
}