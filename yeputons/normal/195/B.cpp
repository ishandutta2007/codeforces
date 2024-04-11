#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pii> ord(m);
    for (int i = 0; i < m; i++)
      ord[i] = mp(abs(m - 1 - 2 * i), i);
    sort(ord.begin(), ord.end());

    set<pii> curs;
    for (int i = 0; i < m; i++) curs.insert(mp(0, i));
    for (int step = 0; step < n; step++) {
      pii x = *curs.begin(); curs.erase(curs.begin());
      printf("%d\n", ord[x.second].second + 1);
      x.first++;
      curs.insert(x);
    }
  }
  return 0;
}