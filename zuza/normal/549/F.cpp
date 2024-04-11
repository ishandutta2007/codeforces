#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1e6 + 123;
const int inf = 1e9;

struct Tour {
  typedef pair<int, int> D;
  int offset;
  vector<D> data;

  Tour(int n)  {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset, {-inf, -inf});
  }

  D get_max(int a, int b) {
    D ans = {-inf, -inf};
    for (a += offset, b += offset; a < b; a >>=1, b >>= 1) {
      if (a&1) ans = max(ans, data[a++]);
      if (b&1) ans = max(ans, data[--b]);
    }
    return ans;
  }

  void update(int x, D val) {
    for (int ptr = x+offset; ptr; ptr /= 2) {
      data[ptr] = max(data[ptr], val);
    }
  }
};

int mod;
int A[MAXN];
int pref[MAXN];

vector<int> idxs[MAXN];

int get_in_range(int lo, int hi, int k) {
  k %= mod; if (k < 0) k += mod;
  return upper_bound(idxs[k].begin(), idxs[k].end(), hi)
    - lower_bound(idxs[k].begin(), idxs[k].end(), lo);
}

llint solve(Tour& T, int lo, int hi) {
  if (lo >= hi) return 0;

  int mid = T.get_max(lo, hi).second;
  llint ans = 0;
  if (mid-lo+1 <= hi-mid) { // iteriraj lijevo
    for (int a = lo; a <= mid; ++a)
      ans += get_in_range(mid+1, hi, pref[a]+A[mid]);
  } else {
    for (int b = mid+1; b <= hi; ++b)
      ans += get_in_range(lo, mid, pref[b]-A[mid]);
  }

  ans += solve(T, lo, mid);
  ans += solve(T, mid+1, hi);
  return ans;
}

int main(void) {
  int n; scanf("%d %d", &n, &mod);
  Tour T(n);

  pref[0] = 0;
  REP(i, n) {
    int x; scanf("%d", &x);
    A[i] = x;
    pref[i+1] = (pref[i] + x) % mod;
    T.update(i, {x, i});
  }

  REP(i, n+1) idxs[ pref[i] ].push_back(i);

  llint ans = solve(T, 0, n);
  printf("%lld\n", ans - n);
  return 0;
}