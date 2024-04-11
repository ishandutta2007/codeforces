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
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pii> szs(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &szs[i].first, &szs[i].second);
    sort(szs.begin(), szs.end());

    for (int i = 0; i + 1 < n; i++) {
      int micnt = szs[i].second;
      int cs = szs[i].first;
      while (micnt > 1 && cs < szs[i + 1].first) {
        micnt = (micnt + 3) / 4;
        cs++;
      }
      szs[i + 1].second = max(szs[i + 1].second, micnt);
    }
    int micnt = szs[n - 1].second;
    int cs = szs[n - 1].first;
    if (micnt == 1) cs++;
    while (micnt > 1) {
      micnt = (micnt + 3) / 4;
      cs++;
    }
    printf("%d\n", cs);
  }
  return 0;
}