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

int n, a[maxn];
vector<int> son[maxn];

int m1, m2;
vector<int> seq;

void solve(int k, bool type) {
  vector<int> nxt_ks;
  for (int t : son[k]) {
    if (!type) {
      m1 = min(m1, t - 1);
    } else {
      m2 = max(m2, t);
    }
    if (!son[t].size()) continue;
    nxt_ks.push_back(t);
  }

  assert(nxt_ks.size() <= 1);

  if (!nxt_ks.size()) {
    for (int t : son[k]) seq.push_back(t);
    assert(seq.size() == n);
  } else {
    int nxt_k = nxt_ks.back();
    for (int t : son[k]) {
      if (t != nxt_k) seq.push_back(t);
    }
    seq.push_back(nxt_k);
    solve(nxt_k, type ^ 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    cin >> n;
    for (int i = 0; i <= n + 1; ++i) son[i].clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      son[a[i]].push_back(i);
    }

    m1 = n, m2 = 0;
    seq.clear();
    if (son[0].size()) {
      solve(0, 0);
    } else {
      solve(n + 1, 1);
    }

    assert(m1 == m2);
    cout << m1 << endl;
    for (int i : seq) cout << i << " ";
    cout << endl;
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/