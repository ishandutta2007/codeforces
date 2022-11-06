#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

#include <functional>
#include <unordered_map>

struct Ppow {
  llint p;
  int e;
};

llint power_mod(llint b, llint e, llint mod) {
  llint ans = 1, p2 = b % mod;
  for (; e; e /= 2, p2 = p2*p2 % mod)
    if (e&1)
      ans = ans*p2 % mod;
  return ans;
}

vector<Ppow> factor(llint x) {
  vector<Ppow> ans;

  for (llint p = 2; x != 1; ++p) {
    if (p*p > x) p = x;
    if (x%p == 0) {
      int e = 0;
      while (x%p == 0) { ++e; x /= p; }
      ans.push_back({p, e});
    }
  }

  return ans;
}

llint calc_phi(const vector<Ppow>& fs) {
  llint ans = 1;
  for (auto f : fs) {
    ans *= power_mod(f.p, f.e-1, 9e18) * (f.p-1);
  }
  return ans;
}

function<llint (llint)> inverse_factory(llint mod) {
  llint phi = calc_phi(factor(mod));
  return [=](llint x) {
    return power_mod(x, phi-1, mod);
  };
}

llint calc_primitive_root(llint mod) {
  llint phi = calc_phi(factor(mod));
  vector<Ppow> fs_phi = factor(phi);

  auto check_is_primitive_root = [&](llint g) {
    if (power_mod(g, phi, mod) != 1) return false;
    for (auto f : fs_phi) {
      if (power_mod(g, phi / f.p, mod) == 1)
        return false;
    }
    return true;
  };

  for (llint g = 1; g < mod; ++g) {
    if (check_is_primitive_root(g))
      return g;
  }

  return -1;
}

// g = primitive root
function<llint (llint)> discrete_logarithm_factory(llint mod, llint& g) {
  g = calc_primitive_root(mod);
  assert(g != -1);

  llint phi = calc_phi(factor(mod));
  llint rt = 1; while (rt*rt < phi) ++rt;
  llint g_inv = power_mod(g, phi-1, mod);
  llint g_mrt = power_mod(g_inv, rt, mod); // g^(-rt)
  
  unordered_map<llint, llint> rainbow;
  REP(y, rt) {
    llint val = power_mod(g, y, mod) % mod;
    rainbow[val] = y;
  }

  return [=](llint a) -> llint {
    auto get = [&](llint key, llint def = 0) {
      auto it = rainbow.find(key);
      if (it != rainbow.end()) return it->second;
      return def;
    };

    llint a_g_mart = a;
    REP(x, rt) {
      if (get(a_g_mart, -1) != -1)
        return (x*rt + get(a_g_mart)) % phi;
      a_g_mart = a_g_mart * g_mrt % mod;
    }

    return -1;    
  };
}

function<llint (llint)> discrete_sqrt_factory(llint mod) { // only rel. prime
  llint g;
  auto discrete_logarithm_mod = discrete_logarithm_factory(mod, g);
  return [=](llint a) -> llint { // the other is -ret
    llint eks = discrete_logarithm_mod(a);
    if (eks%2 == 1) return -1;
    return power_mod(g, eks/2, mod);
  };
}

////////////////

const llint mod = 1e9 + 9;
const int MAXN = 3e5 + 123;

llint inverse(llint x) {
  return power_mod(x, mod-1-1, mod);
}

struct Node {
  llint sum;
  llint prop;

  int sz;
  Node() { prop = 0; sum = 0; }

  void do_prop(llint a, const vector<llint>& powsums) {
    prop = (prop + a) % mod;
    sum = (sum + a*powsums[sz]%mod) % mod;
  }
};

struct Tour {
  int offset, pot;
  vector<Node> data;

  vector<llint> pows;
  vector<llint> powsums;

  Tour(int n, int pot = 2) : pot(pot) {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset);
    FOR(i, offset, 2*offset) data[i].sz = 1;
    for (int i = offset-1; i > 0; --i) {
      data[i].sz = data[2*i].sz + data[2*i+1].sz;
    }

    llint curr = 1;
    for (int i = 0; i < MAXN; ++i, curr = curr*pot % mod)
      pows.push_back(curr);
    
    for (int i = 0; i < MAXN; ++i)
      powsums.push_back(i == 0 ? 0 : (powsums[i-1] + pows[i-1]) % mod);
  }

  int tlo, thi;

  template<typename F>
  void process(int x, int clo, int chi, const F& f) {
    if (chi <= tlo || thi <= clo) return;
    if (tlo <= clo && chi <= thi) if (f(data[x])) return;

    // prop
    if (data[x].prop != 0) {
      data[2*x].do_prop(data[x].prop, powsums);
      data[2*x+1].do_prop(data[x].prop*pows[ data[2*x].sz ]%mod,
                          powsums);
      data[x].prop = 0;
    }

    process(2*x, clo, (clo+chi)/2, f);
    process(2*x+1, (clo+chi)/2, chi, f);

    // upd
    data[x].sum = (data[2*x].sum + data[2*x+1].sum) % mod;
  }

  void add(int lo, int hi, llint koef) { // [lo, hi>
    tlo = lo; thi = hi;
    process(1, 0, offset, [&](Node& x) {
        x.do_prop(koef, powsums);
        koef = koef*pows[x.sz] % mod;
        return true; // done
      });
  }

  llint get_sum(int lo, int hi) { // [lo, hi>
    tlo = lo; thi = hi;
    llint ans = 0;
    process(1, 0, offset, [&](Node& x) {
        ans = (ans + x.sum) % mod;
        return true;
      });
    return ans;
  }
};

/////////////////////////

int main(void) {
  auto inverse = inverse_factory(mod);
  auto sqrt_mod = discrete_sqrt_factory(mod);
  llint d_sqrt5 = sqrt_mod(5); 
  llint d_phi_1 = (1 + d_sqrt5) * inverse(2) % mod;  
  llint d_phi_2 = (1 - d_sqrt5) * inverse(2) % mod;
  llint inv_sqrt5 = inverse(d_sqrt5);

  int nn, nq; scanf("%d %d", &nn, &nq);
  Tour A(nn, d_phi_1), B(nn, d_phi_2);
  REP(i, nn) { 
    int x; scanf("%d", &x);
    A.add(i, i+1, x);
  }

  REP(iq, nq) {
    int type, lo, hi; scanf("%d %d %d", &type, &lo, &hi); --lo;
    if (type == 1) {
      A.add(lo, hi, inv_sqrt5*d_phi_1 % mod);
      B.add(lo, hi, -inv_sqrt5*d_phi_2 % mod);
    } else if (type == 2) {
      llint ans = A.get_sum(lo, hi) + B.get_sum(lo, hi); 
      ans %= mod; ans += mod; ans %= mod;
      printf("%lld\n", ans);
    } else assert(false);      
  }

  return 0;
}