#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<string> vs;

char buf[65536];
int pos;

enum Ty { PREFIX, POSTFIX };

struct Sum {
  int k;
  Ty ty;
  Sum() { k = 0; }
  Sum(int _k, Ty _ty) { k = _k; ty = _ty; }

  bool operator<(const Sum &b) const {
    if (k < b.k) return true;
    if (k > b.k) return false;
    return !ty < !b.ty;
  }
};

Sum parseSum(int sgn) {
  bool wasK = false;
  int k = 0;
  while (buf[pos] >= '0' && buf[pos] <= '9') {
    wasK = true;
    k = k * 10  + buf[pos] - '0';
    pos++;
  }
  if (wasK)
    assert(buf[pos++] == '*');
  else
    k = 1;
  k *= sgn;

  if (buf[pos] == 'a') {
    pos++;
    assert(buf[pos++] == '+');
    assert(buf[pos++] == '+');
    return Sum(k, POSTFIX);
  } else {
    assert(buf[pos++] == '+');
    assert(buf[pos++] == '+');
    assert(buf[pos++] == 'a');    
    return Sum(k, PREFIX);
  }
}

int main() {
  #ifdef DEBUG
  freopen("stdin", "r", stdin);
  freopen("stdout", "w", stdout);
  #endif

  int a;
  while (scanf("%d%s", &a, buf) >= 2) {
    pos = 0;
    vector<Sum> expr;
    while (buf[pos]) {
      int sgn = 1;
      if (pos) {
        assert(buf[pos] == '+' || buf[pos] == '-');
        if (buf[pos] == '-') sgn = -1;
        pos++;
      }
      expr.pb(parseSum(sgn));
    }

    sort(expr.begin(), expr.end());
    int res = 0;
    for (int i = 0; i < expr.size(); i++) {
      eprintf("%d (%d)\n", expr[i].k, expr[i].ty);
      switch (expr[i].ty) {
      case PREFIX: res += ++a * expr[i].k; break;
      case POSTFIX: res += a++ * expr[i].k; break;
      }
    }
    eprintf("---\n");
    printf("%d\n", res);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}