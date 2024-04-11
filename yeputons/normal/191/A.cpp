#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "std"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXL = 12;
const int MAXN = 5e5 + 1e3;
const int INF = 1e9;

struct Edge {
  int a, b, w;
};

Edge es[MAXN];
char buf[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      int l = strlen(buf);
      es[i].a = buf[0] - 'a';
      es[i].b = buf[l - 1] - 'a';
      es[i].w = l;
    }
    
    int ans = 0;
    for (int st = 0; st < 26; st++) {
      vi cls(26, -INF);
      cls[st] = 0;
      for (int i = 0; i < n; i++) {
        int a = es[i].a, b = es[i].b, w = es[i].w;
        if (cls[a] >= 0) cls[b] = max(cls[b], cls[a] + w);
      }
      ans = max(ans, cls[st]);
    }
    printf("%d\n", ans);
  }
  return 0;
}