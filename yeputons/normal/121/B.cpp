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

const int MAXL = 1e5;
char s[MAXL + 10];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d%s", &n, &k, s) >= 1) {
    int p = 0;
    while (p < n && k) {
      while (p + 1 < n && (s[p] != '4' || s[p + 1] != '7'))
        p++;
      if (p + 1 < n) {
        k--;
        if (p % 2 == 0) {
          s[p] = s[p + 1] = '4';
          p++;
        } else {
          s[p] = s[p + 1] = '7';
          p--;
        }
        if (s[p] == '4' && s[p + 1] == '7') {
          k %= 2;
        }
      } else
        break;
    }
    printf("%s\n", s);
  }
  return 0;
}