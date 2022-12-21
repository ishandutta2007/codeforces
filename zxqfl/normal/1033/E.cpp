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

const int A = 1;
const int B = -1;

int rg[1000][1000];

int q[1000];
int src[1000];
int ord[1000];

map<VI, int> cache;

int n;

int query(VI a) {
  if (a.size() == 0 || a.size() == 1) {
    return 0;
  }
  #ifdef zxqfl
  int zz = 0;
  for (int x : a) {
    for (int y : a) {
      if (x != y) {
        zz += rg[x][y];
      }
    }
  }
  return zz / 2;
  #endif
  sort(a.begin(), a.end());
  auto it = cache.find(a);
  if (it != cache.end()) {
    return it->second;
  }
  cout << "? " << a.size() << endl;
  ji(a.size()) {
    cout << a[i];
    if (i+1 == a.size()) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
  cout.flush();
  int ans;
  cin >> ans;
  if (ans == -1) {
    exit(0);
  }
  return cache[a] = ans;
}

int query_between(const VI& b, const VI& a) {
  int v1 = query(a);
  int v2 = query(b);
  VI zz;
  for (int x : a) {
    zz.push_back(x);
  }
  for (int x : b) {
    zz.push_back(x);
  }
  int v3 = query(zz);
  return v3 - v2 - v1;
}

VI by_color(int c) {
  VI ret;
  for (int i = 1; i <= n; i++) {
    if (q[i] == c) {
      ret.push_back(i);
    }
  }
  return ret;
}

void split(const VI& a, VI& b, VI& c) {
  ji(a.size()) {
    if (i % 2 == 0) {
      b.push_back(a[i]);
    } else {
      c.push_back(a[i]);
    }
  }
}

int bin_search(const VI& a, VI b) {
  assert(b.size() != 0);
  if (b.size() == 1) {
    return b[0];
  }
  VI left, right;
  split(b, left, right);
  if (query_between(a, left) != 0) {
    return bin_search(a, move(left));
  } else {
    return bin_search(a, move(right));
  }
}

// VVI EE[1000];

// void cycle(int start, int culprit) {
//   // for (int i = 0; i <= n; i++) {
//   //   if (src[i] != 0) {
//   //     EE[src[i]].push_back(i);
//   //     EE[i].push_back(src[i]);
//   //   }
//   // }
//   VI c;
//   int x = start;
//   while (true) {
//     c.push_back(x);
//     #ifdef zxqfl
//     fprintf(stderr, "culprit = %d, x = %d\n", culprit, x);
//     fflush(stderr);
//     #endif
//     // if (c.size() >= 2 && c.size() % 2 == 1) {
//     //   if (query(VI {x, start})) {
//     if (x == culprit) {
//         cout << "N " << c.size() << endl;
//         ji(c.size()) {
//           cout << c[i];
//           if (i+1 == c.size()) {
//             cout << '\n';
//           } else {
//             cout << ' ';
//           }
//         }
//         exit(0);
//     }
//     assert(src[x] != 0);
//     x = src[x];
//   }
// }

void cycle(int a, int b) {
  VI x, y;
  while (true) {
    if (a == b) {
      reverse(y.begin(), y.end());
      VI zz;
      for (int q : x) {
        zz.push_back(q);
      }
      zz.pb(a);
      for (int q : y) {
        zz.push_back(q);
      }
      cout << "N " << zz.size() << endl;
      ji(zz.size()) {
        cout << zz[i];
        if (i+1 == zz.size()) {
          cout << '\n';
        } else {
          cout << ' ';
        }
      }
      exit(0);
    }
    if (ord[a] < ord[b]) {
      swap(a, b);
      swap(x, y);
    }
    x.push_back(a);
    a = src[a];
  }
}

bool refine(int side) {
  VI a = by_color(side);
  VI b = by_color(-side);
  VI u = by_color(0);
  if (query_between(a, u) == 0) {
    return false;
  }
  int x = bin_search(a, u);
  int y = bin_search(VI{x}, a);
  q[x] = -side;
  src[x] = y;
  ord[x] = ord[y] + 1;
  #ifdef zxqfl
  printf("src[%d] <- %d\n", x, y);
  #endif
  if (query(by_color(-side))) {
    int culprit = bin_search(VI {x}, b);
    cycle(x, culprit);
    assert(false);
  }
  return true;
}

void label() {
  int fails = 0;
  int crnt = A;
  while (true) {
    VI v = by_color(0);
    if (v.empty()) {
      return;
    }
    if (fails == 2) {
      int a = v.back();
      v.pop_back();
      q[a] = A;
      fails = 0;
    }
    crnt = -crnt;
    if (refine(crnt)) {
      fails = 0;
    } else {
      ++fails;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      rg[i][j] = rg[j][i] = rand() % 2;
    }
  }
  label();
  VI a, b;
  for (int i = 1; i <= n; i++) {
    assert(q[i] == A || q[i] == B);
    if (q[i] == A) {
      a.push_back(i);
    } else {
      b.push_back(i);
    }
  }
  cout << "Y " << a.size() << endl;
  ji(a.size()) {
    cout << a[i];
    if (i+1 == a.size()) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
}