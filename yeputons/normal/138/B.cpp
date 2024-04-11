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

const int MAXL = 1e6;
char s[MAXL + 1];

int geta(const string &a, const string &b) {
  assert(a.length() == b.length());

  int c = 0;
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    c += a[i] - '0' + b[i] - '0';
    if (c % 10 != 0) break;

    ans++;
    c /= 10;
  }
  while (c) {
    if (c % 10 != 0) break;
    ans++;
    c /= 10;
  }
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    vi scnt(10);
    for (int i = 0; s[i]; i++)
      scnt[s[i] - '0']++;

    string ba = s, bb = s;
    int bans = geta(ba, bb);

    for (int step = 1; step < 10; step++) {
      vi c1 = scnt;
      vi c2 = scnt;

      string a = "", b = "";
      if (min(c1[step], c2[10 - step]) >= 1) {
        c1[step]--; c2[10 - step]--;

        a += string(1, '0' + step);
        b += string(1, '0' + 10 - step);

        for (int i = 0; i <= 9; i++) {
          int ccnt = min(c1[i], c2[9 - i]);
          a += string(ccnt, '0' + i);
          b += string(ccnt, '0' + 9 - i);
          c1[i] -= ccnt;
          c2[9 - i] -= ccnt;
        }
      }
      int ccnt = min(c1[0], c2[0]);
      a = string(ccnt, '0') + a;
      b = string(ccnt, '0') + b;
      c1[0] -= ccnt;
      c2[0] -= ccnt;

      for (int i = 0; i <= 9; i++) {
        while (c1[i] --> 0)
          a += string(1, '0' + i);
        while (c2[i] --> 0)
          b += string(1, '0' + i);
      }

      int cans = geta(a, b);
      if (cans > bans) {
        bans = cans;
        ba = a;
        bb = b;
      }
    }

    reverse(ba.begin(), ba.end());
    reverse(bb.begin(), bb.end());
    printf("%s\n%s\n", ba.c_str(), bb.c_str());
  }
  return 0;
}