#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i, begin, end)                                \
  for (__typeof(begin) i = (begin), _end = (end),         \
                       _step = 1 - 2 * ((begin) > (end)); \
       i != _end; i += _step)

// OUTPUT
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}

void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
#define print(args...) printr(cout, ##args)

// INPUT
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  rep(i, 0, n) read(A[i]);
}

// DEBUG
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
#define dbg(args...) \
  cout << #args << " = ", dbgr(cout, ##args)  // cout can be changed

#define maxh 20
#define maxn 500050
#define modu 998244353
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a, LL b) {
  uniform_int_distribution<int> u(a, b);
  static mt19937 e(time(0));
  return u(e);
}

LL pw(LL a, LL k = modu - 2) {
  LL ans = 1;
  for (a %= modu; k; k >>= 1) {
    if (k & 1) ans = ans * a % modu;
    a = a * a % modu;
  }
  return ans;
}

int n;
int a[maxn];
int dp[maxn], last_mn[maxn], last_mx[maxn];

int Log2[maxn];

struct Stk {
  int stk[maxn], tp;
  int DP_mn[maxn][maxh];
  void init() { tp = 0; }
  int size() { return tp; }
  int back() { return stk[tp]; }
  int pop() { return --tp; }
  void append(int i) {
    stk[++tp] = i;
    DP_mn[tp][0] = dp[i];
    for (int j = 1; j <= Log2[tp]; ++j) {
      DP_mn[tp][j] = min(DP_mn[tp][j - 1], DP_mn[tp - (1 << j - 1)][j - 1]);
    }
  }

  int pos(int i) {
    assert(1 <= i && i <= tp);
    return stk[i];
  }

} stk_mn, stk_mx;

int ST_mn[maxn][maxh], ST_mx[maxn][maxh];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Log2[0] = -1;
  for (int i = 1; i < maxn; ++i) Log2[i] = Log2[i >> 1] + 1;
  int _;
  read(_);
  while (_--) {
    cin >> n;
    stk_mn.init();
    stk_mx.init();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      ST_mn[i][0] = ST_mx[i][0] = a[i];
      for (int j = 1; j <= Log2[i]; ++j) {
        ST_mn[i][j] = min(ST_mn[i][j - 1], ST_mn[i - (1 << j - 1)][j - 1]);
        ST_mx[i][j] = max(ST_mx[i][j - 1], ST_mx[i - (1 << j - 1)][j - 1]);
      }
      auto get_mn = [&](int ST[maxn][maxh], int l, int r) {
        int t = Log2[r - l + 1];
        return min(ST[l + (1 << t) - 1][t], ST[r][t]);
      };
      auto get_mx = [&](int ST[maxn][maxh], int l, int r) {
        int t = Log2[r - l + 1];
        return max(ST[l + (1 << t) - 1][t], ST[r][t]);
      };
      while (stk_mn.size() && a[stk_mn.back()] > a[i]) stk_mn.pop();
      while (stk_mx.size() && a[stk_mx.back()] < a[i]) stk_mx.pop();
      if (i > 1) {
        if (a[i - 1] < a[i]) {
          int l = 1, r = stk_mn.size();
          while (l < r) {
            int mid = (l + r) >> 1;
            int j = stk_mn.pos(mid);
            if (get_mx(ST_mx, j, i) == a[i])
              r = mid;
            else
              l = mid + 1;
          }
          dp[i] = get_mn(stk_mn.DP_mn, l, stk_mn.size()) + 1;
        } else {
          int l = 1, r = stk_mx.size();
          while (l < r) {
            int mid = (l + r) >> 1;
            int j = stk_mx.pos(mid);
            if (get_mn(ST_mn, j, i) == a[i])
              r = mid;
            else
              l = mid + 1;
          }
          dp[i] = get_mn(stk_mx.DP_mn, l, stk_mx.size()) + 1;
        }
      }

      stk_mn.append(i);
      stk_mx.append(i);
    }
    cout << dp[n] << endl;
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/