#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, m, n;
  while (scanf("%d%d%d", &h, &m, &n) >= 3) {
    vb busy(h, false);
    ll ans = 0;

    map<int, int> poses;

    for (int step = 0; step < n; step++)  {
      char ty;
      int id;
      scanf(" %c%d", &ty, &id);
      if (ty == '+') {
        int hash;
        scanf("%d", &hash);

        while (busy[hash]) {
          ans++;
          hash += m;
          if (hash >= h) hash -= h;
        }
        poses[id] = hash;
        busy[hash] = true;
      } else {
        busy[poses[id]] = false;
      }
    }
    printf("%I64d\n", ans);
  }                                       
  return 0;
}