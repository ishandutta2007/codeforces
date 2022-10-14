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

const int CENT = 350;
const int END = 710;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++) scanf("%d", &as[i]);
    sort(as.begin(), as.end());

    int scnt = 0, stim = 0;
    int ct = 0;
    for (int i = 0; i < sz(as); i++) {
      ct += as[i];
      if (ct > END) break;
      scnt++;
      stim += max(0, ct - CENT);
    }
    printf("%d %d\n", scnt, stim);
  }
  return 0;
}