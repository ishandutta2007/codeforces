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

int p;

ll modpow(ll a, ll b) 
{
  ll ret = 1 % p;
  ll mul = a;
  while (b) {
    if (b & 1) {
      ret *= mul;
      ret %= p;
    }
    mul *= mul;
    mul %= p;
    b >>= 1;
  }
  return ret;
}

struct node;

vector<pair<ll, node*>> current_paths;

struct node {
  ll value;
  int operation;
  node* parent;

  void announce() {
    current_paths.emplace_back(value, this);
  }

  node* add1() {
    node* child = new node;
    child->value = (this->value + 1) % p;
    child->operation = 1;
    child->parent = this;
    child->announce();
    return child;
  }
  node* sub1() {
    node* child = new node;
    child->value = (this->value - 1 + p) % p;
    child->operation = 2;
    child->parent = this;
    child->announce();
    return child;
  }
  node* invert() {
    node* child = new node;
    child->value = modpow(this->value, p-2);
    child->operation = 3;
    child->parent = this;
    child->announce();
    return child;
  }

  void rec(int rem) {
    if (rem == 0) {
      return;
    }
    this->add1()->invert()->rec(rem - 1);
    this->sub1()->invert()->rec(rem - 1);
  }

  void output(VI& ans, bool flip) const {
    if (!parent) {
      return;
    }
    if (!flip) {
      parent->output(ans, flip);
    }
    int q = operation;
    if (flip) {
      if (q == 1) {
        q = 2;
      } else if (q == 2) {
        q = 1;
      }
    }
    ans.pb(q);
    if (flip) {
      parent->output(ans, flip);
    }
  }
};

const int REC_DEPTH = 18;

int main() {
  ll u, v;
  cin >> u >> v >> p;

  node* u_root = new node;
  u_root->value = u;
  u_root->operation = -1;
  u_root->parent = nullptr;
  u_root->rec(REC_DEPTH);

  auto u_paths = current_paths;
  current_paths.clear();

  node* v_root = new node;
  v_root->value = v;
  v_root->operation = -1;
  v_root->parent = nullptr;
  v_root->rec(REC_DEPTH);

  auto v_paths = current_paths;
  current_paths.clear();

  int margin = 200 - REC_DEPTH * 4 - 1;

  sort(u_paths.begin(), u_paths.end());
  sort(v_paths.begin(), v_paths.end());
  int idx = 0;
  for (const auto& up : u_paths) {
    while (idx < v_paths.size() && v_paths[idx].first < up.first) {
      ++idx;
    }
    if (idx == v_paths.size()) {
      printf(":(");
      return 0;
    }
    const auto& vp = v_paths[idx];
    assert(vp.first >= up.first);
    if (vp.first <= up.first + margin) {
      VI ans;
      up.second->output(ans, false);
      jk(vp.first - up.first) {
        ans.pb(1);
      }
      vp.second->output(ans, true);
      cout << ans.size() << endl;
      ji(ans.size()) {
        cout << ans[i] << " ";
      }
      cout << endl;
      return 0;
    }
  }
}