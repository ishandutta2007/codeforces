#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const char* digs[] = {
  "HHH"
  "H H"
  "H H"
  "H H"
  "HHH",

  "  H"
  "  H"
  "  H"
  "  H"
  "  H",

  "HHH"
  "  H"
  "HHH"
  "H  "
  "HHH",

  "HHH"
  "  H"
  "HHH"
  "  H"
  "HHH",

  "H H"
  "H H"
  "HHH"
  "  H"
  "  H",

  "HHH"
  "H  "
  "HHH"
  "  H"
  "HHH",

  "HHH"
  "H  "
  "HHH"
  "H H"
  "HHH",

  "HHH"
  "  H"
  "  H"
  "  H"
  "  H",

  "HHH"
  "H H"
  "HHH"
  "H H"
  "HHH",

  "HHH"
  "H H"
  "HHH"
  "  H"
  "HHH",
};

int get(const char *s, int x, int y) {
  return s[y * 3 + x] != ' ';
}

const int pcnt = 7;
const int xs[] = { 1, 0, 2, 1, 0, 2, 1 };
const int ys[] = { 0, 1, 1, 2, 3, 3, 4 };
int cache[10][10];

int get(char a, char b) {
  if (cache[a][b] >= 0) return cache[a][b];
  int res = 0;
  for (int i = 0; i < pcnt; i++) {
    res += get(digs[a], xs[i], ys[i]) && get(digs[b], xs[i], ys[i]);
  }
  return cache[a][b] = res;
}

const int BEST = 8;

const int MAXN = 1e5;
const int MAXL = 2 * MAXN;

char s[MAXL + 100];

int n, n2;

string restore1(int pos, int minv, int source) {
  assert(pos >= n2);
  string res;
  for (int i = 0; i < pos; i++)
    res += string(1, '0' + s[i]);

  for (int i = n2; i < pos; i++)
    source -= get(s[i - n2], s[i]);

  int firmaxv = 0;
  for (int cval = minv; cval <= 9; cval++)
    firmaxv = max(firmaxv, get(s[pos - n2], cval));

  int crem = firmaxv;
  for (int i = pos + 1; i < n; i++)
    crem += get(s[i - n2], s[i - n2]);

  assert(crem >= source);

  for (int i = pos; i < n; i++) {
    crem -= i == pos ? firmaxv : get(s[i - n2], s[i - n2]);

    bool g = false;
    for (int cval = minv; cval <= 9; cval++) {
      crem += get(s[i - n2], cval);
      if (crem >= source) {
        res += string(1, '0' + cval);
        source -= get(s[i - n2], cval);
        g = true;
      }
      crem -= get(s[i - n2], cval);
      if (g) break;
    }
    minv = 0;
    assert(g);
  }
  assert(source <= 0);
  return res;
}

string restore2(int pos, int minv, int source) {
  int _source = source;

  assert(0 <= pos && pos < n2);
  string res;
  for (int i = 0; i < pos; i++)
    res += string(1, '0' + s[i]);

  int crem = 0;
  for (int i = 0; i < pos; i++)
    crem += get(s[i], s[i]);
  int firmaxv = 0;
  for (int val1 = minv; val1 <= 9; val1++) {
    firmaxv = max(firmaxv, get(val1, val1));
  }
  crem += firmaxv;
  for (int i = pos + 1; i < n2; i++)
    crem += get(BEST, BEST);

//  eprintf("pos=%d, minv=%d, crem=%d, source=%d\n", pos, minv, crem, source);
  assert(crem >= source);
  for (int i = pos; i < n2; i++) {
    crem -= i == pos ? firmaxv : get(BEST, BEST);

    bool g = false;
    for (int cval = minv; cval <= 9; cval++) {
      crem += get(cval, cval);
      if (crem >= source) {
//        eprintf("i=%d, cval=%d\n", i, cval);
        res += string(1, '0' + cval);
        source -= get(cval, cval);
        g = true;
      }
      crem -= get(cval, cval);
      if (g) break;
    }
    minv = 0;
    assert(g);
  }

  for (int i = 0; i < n2; i++)
    s[i] = res[i] - '0';
  return restore1(n2, 0, _source);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  memset(cache, -1, sizeof cache);
  while (scanf("%s", s) >= 1) {
    n = strlen(s);
    n2 = n / 2;
//    eprintf("%s\n", s);

    for (int i = 0; i < n; i++)
      s[i] -= '0';

    int source = 0;
    for (int i = 0; i < n2; i++)
      source += get(s[i], s[i + n2]);

    int cur = source;
    for (int st = n - 1; st >= n2; st--) {
      cur -= get(s[st - n2], s[st]);

      for (int cval = s[st] + 1; cval < 10; cval++) {
        cur += get(s[st - n2], cval);
        if (cur > source) {
          printf("%s\n", restore1(st, s[st] + 1, source + 1).c_str());
          goto end;
        }
        cur -= get(s[st - n2], cval);
      }
      cur += get(s[st - n2], s[st - n2]);
    }

    for (int st = n2 - 1; st >= 0; st--) {
      cur -= get(s[st], s[st]);
      for (int cval = s[st] + 1; cval < 10; cval++) {
        cur += get(cval, cval);
        if (cur > source) {
          printf("%s\n", restore2(st, s[st] + 1, source + 1).c_str());
          goto end;
        }
        cur -= get(cval, cval);
      }
      cur += get(BEST, BEST);
    }
    printf("-1\n");

    end:;
  }
  return 0;
}