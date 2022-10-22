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
LL m;
int fa[maxn];
vector<int> G[maxn];

unordered_map<LL, LL> dp[maxn];
LL s[maxn];

LL dfs(int i, LL cnt) {
  if (dp[i].count(cnt)) return dp[i][cnt];
  LL ans = cnt * s[i];
  if (G[i].size()) {
    LL new_cnt = cnt / G[i].size();
    LL r = cnt % G[i].size();
    if (!r) {
      for (int j : G[i]) {
        ans += dfs(j, new_cnt);
      }
    } else {
      vector<LL> sons;
      for (int j : G[i]) {
        LL t0 = dfs(j, new_cnt);
        LL t1 = dfs(j, new_cnt + 1);
        ans += t0;
        sons.push_back(t1 - t0);
      }
      sort(sons.rbegin(), sons.rend());
      for (int k = 0; k < r; ++k) ans += sons[k];
    }
  }
  return dp[i][cnt] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) G[i].clear(), dp[i].clear();
    for (int i = 2; i <= n; ++i) cin >> fa[i], G[fa[i]].push_back(i);
    for (int i = 1; i <= n; ++i) cin >> s[i];
    cout << dfs(1, m) << endl;
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/