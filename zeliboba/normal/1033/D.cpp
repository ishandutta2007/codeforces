#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

inline li myRand()
{
  li ans = 0;

  forn(i, 4)
    ans <<= 16, ans ^= rand();

  return abs(ans);
}

li mul(li, li, li);

inline li binPow(li a, li b, li mod)
{
  li ans = 1;

  while (b)
  {
    if (b & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }

  return ans;
}

inline li mul(li a, li b, li mod)
{
  li q = li(ld(a) * b / mod);
  li ans = (a * b - q * mod) % mod;
  return ans < 0 ? ans + mod : ans;
}

inline bool isProbablePrime(li n, int cnt)
{
  if (n <= 1) return false;

  forn(t, cnt)
  {
    li a = myRand() % (n - 1) + 1;
    li b = n - 1;
    int cnt = 0;

    while (!(b & 1)) b >>= 1, cnt++;

    li ans = binPow(a, b, n);

    forn(i, cnt)
    {
      li next = mul(ans, ans, n);
      if (next == 1 && ans != 1 && ans != n - 1) return false;
      ans = next;
    }

    if (ans != 1) return false;
  }

  return true;
}

li gcd(li a, li b) { return a == 0 ? b : gcd(b % a, a); }

inline vector<li> pollard(li n)
{ // don't forget about srand :-)
  if (n == 1) return vector<li> (0);
  if (isProbablePrime(n, 13)) return vector<li> (1, n);

  for (li d = 2; d < 100; d++)
    if (n % d == 0)
    {
      vector<li> ans = pollard(d), rg = pollard(n / d);
      forn(i, sz(rg)) ans.pb(rg[i]);
      return ans;
    }

  const int M = 5;
  static li q[M], x[M], y[M];

  forn(i, M) q[i] = myRand() % n, x[i] = y[i] = 2;
  q[0] = 1;

  for (int i = 1, k = 1; ; i++)
  {
    forn(t, M)
    {
      li d = gcd(abs(y[t] - x[t]), n);

      if (d != 1 && d != n)
      {
        vector<li> ans = pollard(d), rg = pollard(n / d);
        forn(i, sz(rg)) ans.pb(rg[i]);
        return ans;
      }

      x[t] = (mul(x[t], x[t], n) + q[t]) % n;

      if (i == k) y[t] = x[t];
    }
    if (i == k) k *= 2;
  }
}

const int mod = 998244353;

li msqrt(li x) {
  li t = sqrt(x);
  while (t * t < x) ++t;
  while (t * t > x) --t;
  return t * t == x ? t : -1;
}

int main()
{
  srand(878637467135649564721679823542635912645897432617958463782564798567814265789234678156756783426176795834157835678213493261478632784678913657826345789632756917284598769782345LL);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vector<int> erat(1500000, 1);
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) {
      erat[j] = 0;
    }
  }
  vector<int> p;
  for (int i = 2; i < erat.size(); ++i) if (erat[i]) {
    p.push_back(i);
  }
  int n;
  cin >> n;
  vector<li> a(n), d2;
  map<li, int> c;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (li x : p) {
      if (x * x * x > a[i]) break;
      while (a[i] % x == 0) {
        a[i] /= x;
        c[x]++;
      }
    }
    if (a[i] > 1) {
      if (isProbablePrime(a[i], 13)) {
        c[a[i]]++;
      } else {
        li t = msqrt(a[i]);
        if (t >= 0) {
          c[t] += 2;
        } else {
          d2.push_back(a[i]);
        }
      }
    }
//    auto f = pollard(a[i]);
//    for (auto x : f) c[x]++;
  }
  sort(d2.begin(), d2.end());
  for (int t = 0; t < n; ++t) {
    bool go = false;
    for (int i = (int)d2.size() - 1; i >= 0; --i) {
      for (auto it : c) {
        li d = it.first;
        if (d2[i] % d == 0) {
          c[d]++;
          c[d2[i] / d]++;
          d2.erase(d2.begin() + i);
          go = true;
          break;
        }
      }
    }
    for (int i = (int)d2.size() - 1; i >= 0; --i) {
      for (int j = i - 1; j >= 0; --j) if (d2[i] != d2[j]) {
        li d = __gcd(d2[i], d2[j]);
        if (d > 1) {
          c[d]++;
          c[d2[i] / d]++;
          d2.erase(d2.begin() + i);
          go = true;
          break;
        }
      }
    }
    if (!go) break;
  }
  map<li, int> c2;
  for (li x : d2) c2[x]++;
  li res = 1;
  for (auto it : c) {
    res = res * (it.second + 1) % mod;
  }
  for (auto it : c2) {
    res = res * (it.second + 1) % mod * (it.second + 1) % mod;
  }
  cout << res << endl;
  return 0;
}