#include <map>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <cassert>

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

vector<vector<int>> operations;

int base[50][50];

int original_nr;
int original_nc;

struct View {
  int r, c;
  int nr, nc;
  bool inverted;

  PII true_coord(int a, int b) const {
    assert(a >= 0);
    assert(b >= 0);
    assert(a < nr);
    assert(b < nc);
    if (inverted) {
      return {c+b, r+a};
    } else {
      return {r+a, c+b};
    }
  }

  int desired(int a, int b) const {
    auto pr = true_coord(a, b);
    return pr.first * original_nc + pr.second + 1;
  }

  int& operator()(int a, int b) const {
    auto pr = true_coord(a, b);
    return base[pr.first][pr.second];
  }

  View invert() const {
    auto v = *this;
    v.inverted = !v.inverted;
    swap(v.r, v.c);
    swap(v.nr, v.nc);
    return v;
  }

  View advance() const {
    auto v = *this;
    v.c++;
    v.nc--;
    return v;
  }

  pair<int, int> find(int x) const {
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        if ((*this)(i, j) == x) {
          return {i, j};
        }
      }
    }
    assert(false);
  }

  bool done() {
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        if ((*this)(i, j) != desired(i, j)) {
          return false;
        }
      }
    }
    return true;
  }
};

void pp() {
  return;
  printf("\n");
  for (int i = 0; i < original_nr; i++) {
    for (int j = 0; j < original_nc; j++) {
      printf("%d ", base[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void rot(int& a, int& b, int& c, int& d) {
  operations.push_back({a, b, c, d});
  int save = d;
  d = c;
  c = b;
  b = a;
  a = save;
  pp();
}

void rot8(
  int& a, int& b, int& c, int& d,
  int& e, int& f, int& g, int& h
) {
  operations.push_back({a, b, c, d, e, f, g, h});
  int save = h;
  h = g;
  g = f;
  f = e;
  e = d;
  d = c;
  c = b;
  b = a;
  a = save;
  pp();
}

void clockwise(View v, pair<int, int> pos) {
  int r = pos.first;
  int c = pos.second;
  int& va = v(r, c);
  int& vb = v(r, c+1);
  int& vc = v(r+1, c+1);
  int& vd = v(r+1, c);
  rot(va, vb, vc, vd);
}

void counter_clockwise(View v, pair<int, int> pos) {
  int r = pos.first;
  int c = pos.second;
  int& va = v(r, c);
  int& vb = v(r+1, c);
  int& vc = v(r+1, c+1);
  int& vd = v(r, c+1);
  rot(va, vb, vc, vd);
}

void big(View v, bool cw) {
  int& a = v(0, 0);
  int& b = v(0, 1);
  int& c = v(0, 2);
  int& d = v(1, 0);
  // int& e = v(1, 1);
  int& f = v(1, 2);
  int& g = v(2, 0);
  int& h = v(2, 1);
  int& i = v(2, 2);
  if (cw) {
    rot8(a, b, c, f, i, h, g, d);
  } else {
    rot8(d, g, h, i, f, c, b, a);
  }
}

void swap_ab(View v) {
  printf("hello\n");
  counter_clockwise(v, {0, 1});
  big(v, true);
  clockwise(v, {0, 1});
  big(v, false); 
}

void bring(View v, pair<int, int> src, pair<int, int> dst) {
  while (src != dst) {
    int old = v(src.first, src.second);
    if (src.first < dst.first) {
      if (src.second == 0) {
        counter_clockwise(v, src);
      } else {
        clockwise(v, {src.first, src.second - 1});
      }
    } else if (src.first > dst.first) {
      if (src.second + 1 == v.nc) {
        counter_clockwise(v, {src.first - 1, src.second - 1});
      } else {
        clockwise(v, {src.first - 1, src.second});
      }
    } else if (src.second > dst.second) {
      if (src.first == 0) {
        counter_clockwise(v, {src.first, src.second - 1});
      } else {
        clockwise(v, {src.first - 1, src.second - 1});
      }
    } else {
      assert(src.second < dst.second);
      if (src.first == 0) {
        clockwise(v, src);
      } else {
        counter_clockwise(v, {src.first - 1, src.second});
      }
    }
    src = v.find(old);
  }
}

int old_base[50][50];

void final(View v) {
  auto old_operations = operations;
  jij(original_nr, original_nc) {
    old_base[i][j] = base[i][j];
  }
  int cnt = 0;
  while (!v.done()) {
    ++cnt;
    if (rand() % 3 == 0) {
      big(v, rand() % 2);
    } else {
      if (rand() % 2) {
        clockwise(v, {rand() % 2, rand() % 2});
      } else {
        counter_clockwise(v, {rand() % 2, rand() % 2});
      }
    }
    if (cnt == 100) {
      cnt = 0;
      operations = old_operations;
      jij(original_nr, original_nc) {
        base[i][j] = old_base[i][j];
      }
    }
  }
  int middle = v.desired(1, 1);
  bring(v, v.find(middle), {1, 1});
  vector<int> dd;
  dd.push_back(v.desired(0, 0));
  dd.push_back(v.desired(0, 1));
  dd.push_back(v.desired(0, 2));
  dd.push_back(v.desired(1, 2));
  dd.push_back(v.desired(2, 2));
  dd.push_back(v.desired(2, 1));
  dd.push_back(v.desired(2, 0));
  dd.push_back(v.desired(1, 0));
  auto dord = [&](int x) {
    // printf("dord(%d)\n", x);
    for (size_t i = 0; i < dd.size(); i++) {
      if (dd[i] == x) {
        return i;
      }
    }
    // printf("%d\n", x);
    // assert(false);
    return size_t(100);
  };
  while (true) {
    if (dord(v(0, 0)) > dord(v(0, 1))) {
      swap_ab(v);
    }
    if (v.done()) {
      break;
    }
    big(v, true);
  }
}

void solve(View v) {
  if (v.nr > v.nc) {
    return solve(v.invert());
  }
  if (v.nr == 3 && v.nc == 3) {
    return final(v);
  }
  auto adv = v.advance();
  for (int i = v.nr - 1; i >= 1; i--) {
    int pivot = v.desired(i, 0);
    auto pos = v.find(pivot);
    if (pos.second == 0) {
      if (pos.first == 0) {
        clockwise(v, pos);
      } else {
        counter_clockwise(v, {pos.first - 1, pos.second});
      }
    }
    bring(adv, adv.find(pivot), {i, 0});
    clockwise(v, {i - 1, 0});
  }
  int final = v.desired(0, 0);
  auto pos = v.find(final);
  if (pos != make_pair(0, 0)) {
    if (pos == make_pair(1, 1)) {
      clockwise(v, pos);
    }
    clockwise(v, {0, 0});
    bring(adv, adv.find(final), {0, 0});
    counter_clockwise(v, {0, 0});
  }
  solve(adv);
}

int main() {
  View v;
  v.r = 0;
  v.c = 0;
  v.inverted = false;
  rint(v.nr);
  rint(v.nc);
  original_nr = v.nr;
  original_nc = v.nc;
  for (int r = 0; r < v.nr; r++) {
    for (int c = 0; c < v.nc; c++) {
      rint(v(r, c));
    }
  }
  solve(v);
  printf("%d\n", (int) operations.size());
  for (auto& x : operations) {
    printf("%d", (int) x.size());
    for (int k : x) {
      printf(" %d", k);
    }
    printf("\n");
  }
}