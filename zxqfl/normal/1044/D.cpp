#include <map>
#include <unordered_map>
#include <cstdio>
#include <vector>

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

int sgn(int x) {
  if (x > 0) {
    return 1;
  }
  if (x < 0) {
    return -1;
  }
  return 0;
}

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

struct info {
  int parent = -1;
  int sum = 0;
};

unordered_map<int, info> parent;

pair<int, int> climb(int x) {
  auto it = parent.find(x);
  if (it == parent.end() || it->second.parent == x) {
    return {x, 0};
  } else {
    auto pr = climb(it->second.parent);
    it->second.parent = pr.first;
    it->second.sum ^= pr.second;
    return {it->second.parent, it->second.sum};
  }
}

void update(int a, int b, int v) {
  ++b;
  // printf("%d..%d=%d\n", a, b, v);
  auto apr = climb(a);
  auto bpr = climb(b);
  if (apr.first == bpr.first) {
    return;
  }
  info i;
  i.parent = bpr.first;
  i.sum = apr.second ^ bpr.second ^ v;
  parent[apr.first] = i;
}

int query(int a, int b)  {
  ++b;
  // printf("q %d..%d\n", a, b);
  auto apr = climb(a);
  auto bpr = climb(b);
  if (apr.first == bpr.first) {
    return apr.second ^ bpr.second;
  } else {
    return -1;
  }
}

int main() {
  int q;
  rint(q);
  int last = 0;
  while (q--) {
    int t;
    rint(t);
    if (t == 1) {
      int lp, rp, xp;
      rint(lp);
      rint(rp);
      rint(xp);
      int l = lp ^ last;
      int r = rp ^ last;
      int x = xp ^ last;
      if (l > r) {
        swap(l, r);
      }
      int existing = query(l, r);
      if (existing == -1) {
        update(l, r, x);
      }
    } else {
      int lp, rp;
      rint(lp);
      rint(rp);
      int l = lp ^ last;
      int r = rp ^ last;
      if (l > r) {
        swap(l, r);
      }
      int existing = query(l, r);
      printf("%d\n", existing);
      if (existing == -1) {
        last = 1;
      } else {
        last = existing;
      }
    }
  }
}