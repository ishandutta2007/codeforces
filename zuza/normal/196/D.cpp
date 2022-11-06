#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = 4e5 + 123;
const llint mod = 1e9 + 7;
const llint P = 3137;
llint Pinv = -1;

struct Loga {
  int n; vector<llint> data;
  Loga(int n) : n(n), data(n+1, 0) {}
  llint query(int x) {
    llint sum = 0; for (; x; x -= x&-x) sum += data[x];
    return sum;
  }
  llint query(int a, int b) { return query(b) - query(a); }
  void update(int x, llint delta) {
    for (++x; x < (int)data.size(); x += x&-x)
      data[x] += delta;
  }
};

llint Ppot[MAXN], Pinvpot[MAXN];

struct HS {
  int len;
  vector<char> S;
  Loga loga;

  HS(int len) : len(len), S(len, 0), loga(len) {}
  void update(int x, char c) {
    loga.update(x, -Ppot[x]*S[x]%mod);
    S[x] = c;
    loga.update(x, +Ppot[x]*S[x]%mod);
  }
  llint get_hash(int a, int b) {
    llint ans = loga.query(a, b) % mod;
    ans = ans * Pinvpot[a] % mod;    
    return ans;
  }
};


int main(void)
{
  { static llint invs[P+1];
    invs[1] = 1; for (llint i = 2; i <= P; ++i) invs[i] = (mod - mod/i) * invs[mod%i] % mod;
    Pinv = invs[P];
    assert(P * Pinv % mod == 1);

    Ppot[0] = 1; REP(i, MAXN) Ppot[i+1] = Ppot[i] * P % mod;
    Pinvpot[0] = 1; REP(i, MAXN) Pinvpot[i+1] = Pinvpot[i] * Pinv % mod;
  }

  int d; scanf("%d", &d);
  static char buff[MAXN]; scanf("%s", buff); int len = strlen(buff);

  HS norm(len), rev(len);
  auto update = [&](int x, char c) {
    norm.update(x, c);
    rev.update(len-1-x, c);
  };
  REP(i, len) update(i, buff[i]);
  auto bad_last = [&](int x) {
    // d
    if (x+1-d >= 0) {
      llint Anorm = norm.get_hash(x+1-d, x+1);
      llint Arev = rev.get_hash(len-(x+1), len-(x+1-d));
      if (Anorm == Arev) return true;
    }
    // d+1
    if (x+1-(d+1) >= 0) {
      llint Bnorm = norm.get_hash(x+1-(d+1), x+1);
      llint Brev = rev.get_hash(len-(x+1), len-(x+1-(d+1)));
      if (Bnorm == Brev) return true;
    }

    return false;
  };

  int ptr = 0;
  REP(i, len+1) {
    ptr = i;
    if (i < len) if (bad_last(i)) break;
  }
  if (ptr == len) ptr = len-1;

  do {
    if (buff[ptr] == 'z') {
      --ptr;
      continue;
    }
    ++buff[ptr]; update(ptr, buff[ptr]);
    if (!bad_last(ptr)) break;
  } while(ptr >= 0);

  if (ptr == -1) { puts("Impossible"); exit(0); }

  ++ptr;
  while (ptr < len) {
    char c; for (c = 'a'; c <= 'z'; ++c) {
      buff[ptr] = c; update(ptr, c);
      if (!bad_last(ptr)) break;
    }
    assert(c <= 'z');
    ++ptr;
  }

  puts(buff);
  return 0;
}