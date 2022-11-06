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
typedef vector<long long> Poly;

const llint mod = 998244353; // 7.17.2^23 + 1

namespace ntt {
  const int G_ordpow = 23; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  const llint G = 15311432; // = 3^(7*17), root with order 2^23

  const int MAXSZ = 1<<20; // 4*8 MB = 32 MB extra
  llint A[MAXSZ], B[MAXSZ], C[MAXSZ];

  void fft(llint* A, int sz, llint omega) {
    if (sz == 1) return ;

    int half = sz / 2;
    static llint place[MAXSZ];
    REP(i, half) place[i] = A[2*i], place[i+half] = A[2*i+1];
    REP(i, sz) A[i] = place[i];

    fft(A, half, omega*omega % mod);
    fft(A+half, half, omega*omega % mod);

    llint koef = 1;
    REP(i, half) {
      llint p = A[i], q = A[i+half];
      A[i] = (p + koef*q) % mod;
      A[i+half] = (p - koef*q) % mod;
      koef = koef*omega % mod;
    }
  }

  Poly mult(const Poly& a, const Poly& b) {
    int sz = a.size()-1 + b.size()-1 + 1;
    int pot2 = 1; while (pot2 < sz) pot2 *= 2;
    llint omega = G;
    REP(i, G_ordpow - __builtin_ctz(pot2)) omega = omega*omega % mod;

    REP(i, pot2) A[i] = (i < (int)a.size()) ? a[i] : 0;
    REP(i, pot2) B[i] = (i < (int)b.size()) ? b[i] : 0;

    fft(A, pot2, omega);
    fft(B, pot2, omega);

    REP(i, pot2) C[i] = A[i]*B[i] % mod;
    fft(C, pot2, omega);
    reverse(C+1, C+pot2);

    Poly ans;
    REP(i, sz) {
      llint inv = mod - (mod-1)/pot2; assert(pot2*inv % mod == 1);
      ans.push_back(C[i]*inv % mod); 
    }
    return ans;
  }
};

llint power_mod(llint a, llint e) {
  llint ans = 1, p2 = a;
  for (; e; e /= 2) {
    if (e&1) ans = ans*p2 % mod;
    p2 = p2*p2 % mod;
  }
  return ans % mod;
}
llint inv(llint a) { return power_mod(a, mod-2); }

Poly crop(Poly a, int sz) { a.resize(sz, 0); return a; }
Poly operator * (const Poly& a, const Poly& b) {
  return ntt::mult(a, b);
}
Poly operator * (llint k, Poly p) {
  REP(i, p.size()) p[i] = p[i]*k % mod;
  return p;
}
Poly operator + (const Poly& a, const Poly& b) {
  Poly ans(max(a.size(), b.size()), 0);
  REP(i, a.size()) ans[i] += a[i];
  REP(i, b.size()) ans[i] += b[i];
  REP(i, ans.size()) ans[i] %= mod;
  return ans;
}

Poly operator - (const Poly& a, const Poly& b) { return a + (-1)*b; }


// power series inverse, sz same as f
// R_{2n}(z)=2R_n(z)-R_n(z)^2F(z) (mod z^{2n})
Poly inv(const Poly& f) {
  int sz = f.size();
  assert((sz&(sz-1)) == 0); // sz must be 2^k
  assert(f[0] != 0);
  int e2 = __builtin_ctz(sz);

  Poly ans = { inv(f[0]) };
  REP(i, e2) {
    int pot = 1<<i;
    ans = 2*ans - crop(ans*ans*crop(f, 2*pot), 2*pot);
  }
  return ans;
}

// power series square root, sz same as f
// S_{2n}(z) = 1/2 (S_n(z) + F(z) S_n(z)^-1)
Poly sqrt(const Poly& f) {
  int sz = f.size();
  assert((sz&(sz-1)) == 0); // sz must be 2^k
  assert(f[0] == 1); // find the modular root! Cipolla?
  int e2 = __builtin_ctz(sz);

  Poly ans = { 1 }; // = square_root(f[0])
  REP(i, e2) {
    int pot = 1<<i;
    ans = crop(inv(2) * (ans + f*inv(crop(ans, 2*pot))), 2*pot);
  }

  return ans;
}

int main(void) {
  int nc, nq; scanf("%d %d", &nc, &nq);
  int min_sz = nq + 1;

  int sz = 1; while (sz < min_sz) sz *= 2;
  Poly C(sz, 0);

  REP(i, nc) {
    int x; scanf("%d", &x);
    if (x < (int)C.size()) C[x] = 1;
  }

  Poly ans = -4*C; ans[0] += 1;
  ans = sqrt(ans); ans[0] += 1;
  ans = 2 * inv(ans);

  FOR(i, 1, nq+1) {
    printf("%lld\n", (ans[i]%mod + mod)%mod);
  }

  return 0;
}