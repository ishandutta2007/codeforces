#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vector<int> cnts(31);
    for (int i = 0; i < m; i++) {
      int x = 0;
      scanf("%d", &x), cnts[x]++;
    }

    int ans = 0;

    deque<int> curs;
    for (int k = 0; k < 30; k++) {
      for (int i = 0; i < cnts[k]; i++)
        curs.push_front(1);

      for (int i = 0; i < n && !curs.empty(); i++) if (as[i] & 1) {
        as[i]--;
        ans += curs.back();
        curs.pop_back();
      }

      deque<int> nes;
      while (!curs.empty()) {
        int a = curs.back(); curs.pop_back();
        if (!curs.empty()) {
          a += curs.back(); curs.pop_back();
        }
        nes.push_front(a);
      }
      nes.swap(curs);

      for (int i = 0; i < n; i++)
        as[i] >>= 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}