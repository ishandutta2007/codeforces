#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
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
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    sort(as.begin(), as.end());
    vi res = as;
    if (as[n - 1] == 1) {
      res[n - 1] = 2;
    } else {
      res.insert(res.begin(), 1);
      res.resize(n);
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", res[i], "\n "[i + 1 < n]);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}