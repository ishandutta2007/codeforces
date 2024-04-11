#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); ++i)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define jij2d(v) jij((v).size(), (v)[i].size())
#define jjdescent(i, s, e) for (int i = (s)-1; i >= int(e); --i)
#define jjrev(i, s) jjdescent(i, s, 0)
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((long long) 1e16)
#define pb push_back
#define mp make_pair

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
  char c, r = 0, n = 0;
  x = 0;
  while (true)
    {
      c = getchar();
      if (c < 0 && !r)
        return 0;
      else if (c == '-' && !r)
        n = 1;
      else if (c >= '0' && c <= '9')
        x = x * 10 + c - '0', r = 1;
      else if (r)
        break;
    }
  if (n)
    x = -x;
  return 1;
}

template<typename T>
vector<T> readIntegral(int n)
{
  vector<T> ret(n);
  for (int i = 0; i < n; i++)
    readInteger(ret[i]);
  return ret;
}

auto readInts = readIntegral<int>;
auto readLongs = readIntegral<long long>;

template<typename T>
vector<vector<T>> make2d(size_t r, size_t c)
{
  return vector<vector<T>>(r, vector<T>(c));
}

template<typename T>
vector<vector<T>> make2d(size_t r, size_t c, const T& def)
{
  return vector<vector<T>>(r, vector<T>(c, def));
}

template <typename T, T MOD>
struct ModInt
{
  T value;
  ModInt() : value(0)
  {}
  ModInt(T x)
  {
    x %= MOD;
    if (x < 0)
      x += MOD;
    value = x;
  }

public:
  ModInt& operator += (ModInt x)
  {
    value += x.value;
    if (value >= MOD)
      value -= MOD;
    return *this;
  }
  ModInt& operator -= (ModInt x)
  {
    value -= x.value;
    if (value < 0)
      value += MOD;
    return *this;
  }
  ModInt& operator *= (ModInt x)
  {
    value *= x.value;
    value %= MOD;
    return *this;
  }
  ModInt& operator /= (ModInt x)
  {
    x.invert();
    return *this *= x;
  }

  ModInt operator + (ModInt x) const
  {
    ModInt o = *this;
    o += x;
    return o;
  }
  ModInt operator - (ModInt x) const
  {
    ModInt o = *this;
    o -= x;
    return o;
  }
  ModInt operator * (ModInt x) const
  {
    ModInt o = *this;
    o *= x;
    return o;
  }
  ModInt operator / (ModInt x) const
  {
    ModInt o = *this;
    o /= x;
    return o;
  }
  bool operator == (ModInt x) const
  {
    return value == x.value;
  }
  bool operator != (ModInt x) const
  {
    return !(*this == x);
  }

  ModInt operator - () const
  {
    return ModInt(0) - *this;
  }

  ModInt operator ^ (long long x) const
  {
    ModInt ret = 1 % MOD;
    ModInt mul = *this;
    while (x)
      {
        if (x & 1)
          ret *= mul;
        mul *= mul;
        x >>= 1;
      }
    return ret;
  }
  ModInt& operator ^= (long long x)
  {
    return *this = *this ^ x;
  }

private:
  void invert()
  {
    *this ^= MOD-2;
  }
public:
  friend ostream& operator << (ostream& out, const ModInt& x)
  {
    return out << x.value;
  }
};

template<typename T>
using v2d = vector<vector<T>>;

typedef ModInt<long long, 1000000007> mint;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef v2d<int> VVI;
typedef vector<ll> VLL;
typedef v2d<ll> VVLL;
typedef vector<char> VCH;
typedef v2d<char> VVCH;

ll n, D;

VI children[4000];

ll MOD = 1000000007;

VLL f(int x) {
  vector<VLL> cfs;
  for (int o : children[x]) {
    cfs.pb(f(o));
  }
  VLL result(n+1);
  ji(result.size()) {
    ll prod = 1;
    for (auto& x : cfs) {
      prod *= x[i];
      prod %= MOD;
    }
    result[i] = prod;
    if (i > 0) {
      result[i] += result[i-1];
      result[i] %= MOD;
    }
  }
  return result;
}

VLL master;

ll divdif[4000][4000];
mint mod_inverse_of[4000];

mint dd(int a, int b) {
  ll& ans = divdif[a][b];
  if (ans != -1) {
    return ans;
  }
  if (a == b) {
    ans = master[a];
  } else {
    mint num = dd(a+1, b) - dd(a, b-1);
    ll den = b - a;
    ans = (num * mod_inverse_of[den]).value;
  }
  return ans;
}

int main() {
  ji(4000) {
    mod_inverse_of[i] = mint(1) / mint(i);
  }
  jij(4000, 4000) {
    divdif[i][j] = -1;
  }
  rint(n);
  rint(D);
  --D;
  ji(n-1) {
    int super;
    rint(super);
    children[super-1].pb(i+1);
  }
  master = f(0);
  mint xmprod = 1;
  mint ans = 0;
  ji(master.size()) {
    // cerr << i << ": " << master[i] << endl;
    ans += dd(0, i) * xmprod;
    xmprod *= D - i;
  }
  cout << ans.value << endl;
}