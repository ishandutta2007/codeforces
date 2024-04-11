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

char s[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      if (strlen(s) > 10) {
        printf("%c%d%c\n", s[0], strlen(s) - 2, s[strlen(s) - 1]);
      } else
        printf("%s\n", s);
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}