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
LL a[maxn], ls[maxn], rs[maxn];

LL pw2[maxn];
LL F[maxn], FI[maxn], I[maxn];

LL C(LL n, LL m) { return F[n] * FI[m] % modu * FI[n - m] % modu; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  F[0] = I[0] = I[1] = FI[0] = 1;
  for (int i = 1; i < maxn; ++i) F[i] = F[i - 1] * i % modu;
  for (int i = 2; i < maxn; ++i) I[i] = modu - modu / i * I[modu % i] % modu;
  for (int i = 1; i < maxn; ++i) FI[i] = FI[i - 1] * I[i] % modu;

  for (int i = 1; i < maxn; ++i) assert(I[i] * i % modu == 1);
  for (int i = 0; i < maxn; ++i) assert(F[i] * FI[i] % modu == 1);

  pw2[0] = 1;
  for (int i = 1; i < maxn; ++i) pw2[i] = pw2[i - 1] * 2 % modu;

  int _;
  read(_);
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ls[0] = rs[n + 1] = 0;
    for (int i = 1; i <= n; ++i) ls[i] = ls[i - 1] + a[i];
    for (int i = n; i; --i) rs[i] = rs[i + 1] + a[i];

    LL ans = 1;
    for (int l1 = 1, r2 = n; l1 <= n; ++l1) {
      while (r2 >= l1 + 1 && rs[r2] < ls[l1]) --r2;
      if (r2 < l1 + 1 || rs[r2] != ls[l1]) continue;

      if (ls[r2 - 1] == ls[l1]) {
        LL sum = pw2[r2 - l1];
        ans = ans * sum % modu;
        break;
      } else {
        int r1 = l1;
        int l2 = r2;
        while (ls[r1] == ls[l1]) ++r1;
        while (rs[l2] == rs[r2]) --l2;

        assert(l2 + 1 > r1 - 1);

        LL sum = 0;
        for (int c = 0; c <= r1 - l1 && c <= r2 - l2; ++c) {
          LL t = C(r1 - l1, c) * C(r2 - l2, c);
          sum = (sum + t) % modu;
        }
        ans = ans * sum % modu;

        l1 = r1 - 1;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/