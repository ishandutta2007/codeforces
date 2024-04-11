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

namespace stanford {
  typedef vector<double> VD;
  typedef vector<VD> VVD;
  typedef vector<int> VI;

  double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
    int n = int(cost.size());

    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
      u[i] = cost[i][0];
      for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
      v[j] = cost[0][j] - u[0];
      for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }
  
    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Rmate[j] != -1) continue;
        if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
          Lmate[i] = j;
          Rmate[j] = i;
          mated++;
          break;
        }
      }
    }
  
    VD dist(n);
    VI dad(n);
    VI seen(n);
  
    // repeat until primal solution is feasible
    while (mated < n) {
    
      // find an unmatched left node
      int s = 0;
      while (Lmate[s] != -1) s++;
    
      // initialize Dijkstra
      fill(dad.begin(), dad.end(), -1);
      fill(seen.begin(), seen.end(), 0);
      for (int k = 0; k < n; k++) 
        dist[k] = cost[s][k] - u[s] - v[k];
    
      int j = 0;
      while (true) {
      
        // find closest
        j = -1;
        for (int k = 0; k < n; k++) {
          if (seen[k]) continue;
          if (j == -1 || dist[k] < dist[j]) j = k;
        }
        seen[j] = 1;
      
        // termination condition
        if (Rmate[j] == -1) break;
      
        // relax neighbors
        const int i = Rmate[j];
        for (int k = 0; k < n; k++) {
          if (seen[k]) continue;
          const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
          if (dist[k] > new_dist) {
            dist[k] = new_dist;
            dad[k] = j;
          }
        }
      }
    
      // update dual variables
      for (int k = 0; k < n; k++) {
        if (k == j || !seen[k]) continue;
        const int i = Rmate[k];
        v[k] += dist[k] - dist[j];
        u[i] -= dist[k] - dist[j];
      }
      u[s] += dist[j];
    
      // augment along path
      while (dad[j] >= 0) {
        const int d = dad[j];
        Rmate[j] = Rmate[d];
        Lmate[Rmate[j]] = j;
        j = d;
      }
      Rmate[j] = s;
      Lmate[s] = j;
    
      mated++;
    }
  
    double value = 0;
    for (int i = 0; i < n; i++)
      value += cost[i][Lmate[i]];
  
    return value;
  }
}

int _solve(VI a) {
  int N = a.size() / 2;
  VVI posns(N);
  ji(a.size()) {
    posns[a[i]].pb(i);
  }
  using namespace stanford;
  VVD cost(N, VD(N));
  jij(N, N) {
    assert(posns[i].size() == 2);
    int x1 = posns[i][0];
    int x2 = posns[i][1];
    int y1 = j*2;
    int y2 = j*2+1;
    int c =
      min(abs(x1 - y1) + abs(x2 - y2),
          abs(x1 - y2) + abs(x2 - y1));
    cost[i][j] = c;
  }
  VI zz, zzz;
  return MinCostMatching(cost, zz, zzz) / 2;
}

int solve(VI a) {
  int N = a.size() / 2;
  int ans = 0;
  ji(N) {
    int x = a[i*2];
    int start = i*2+1;
    int j = start;
    while (a[j] != x) {
      ++j;
    }
    while (j > start) {
      swap(a[j], a[j-1]);
      --j;
      ++ans;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  VI a(2*n);
  ji(2*n) cin >> a[i];
  ji(2*n) --a[i];
  int ans = solve(a);
  cout << ans << endl;
}