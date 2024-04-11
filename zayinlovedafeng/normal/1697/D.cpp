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

#define maxc 26
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

string S = "aksjyfklsdahbfukafgui";

char ask1(int i) {
  cout << "? 1 " << i << endl;
  //   return S[i - 1];
  string s;
  cin >> s;
  return s[0];
}

int ask2(int l, int r) {
  cout << "? 2 " << l << " " << r << endl;
  //   set<char> st(S.begin() + l - 1, S.begin() + r);
  //   return st.size();
  int resp;
  cin >> resp;
  return resp;
}

int n;
char s[maxn];

int pos[maxc];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  //   n = S.size();
  cin >> n;
  memset(pos, 0x3f, sizeof(pos));

  s[1] = ask1(1);
  pos[s[1] - 'a'] = 1;
  for (int i = 2, last = 1; i <= n; ++i) {
    int cnt = ask2(1, i);
    if (cnt != last) {
      s[i] = ask1(i);
      pos[s[i] - 'a'] = i;
      //   dbg(i, s[i]);
    }
    last = cnt;
  }

  for (int i = 2; i <= n; ++i) {
    if (!s[i]) {
      vector<int> ps;
      for (int c = 0; c < maxc; ++c)
        if (pos[c] < i) ps.push_back(pos[c]);
      sort(ps.begin(), ps.end());
      int l = 0, r = ps.size() - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (ask2(ps[mid], i) == ps.size() - mid)
          l = mid;
        else
          r = mid - 1;
      }
      //   dbg(ps, l);
      s[i] = s[ps[l]];
      //   dbg(i, s[i]);
    }
    pos[s[i] - 'a'] = i;
  }
  cout << "! " << s + 1 << endl;
  return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/