#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

vb was;
vvi es;

int ccol;
bool wasBad, wasEdge;
vi deg;

void dfs(int v) {
  if (was[v]) return;
  if (deg[v] & 1) wasBad = true;
  was[v] = true;
  for (int i = 0; i < sz(es[v]); i++) {
    wasEdge = true;
    dfs(es[v][i]);
  }
}

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    deg = vi(n);
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
      deg[a]++;
      deg[b]++;
    }

    int need = 0;
    for (int i = 0; i < n; i++)
      need += deg[i] & 1;
    assert(need % 2 == 0);
    need /= 2;

    was = vb(n, false);
    int badCnt = 0, goodCnt = 0;
    for (int i = 0; i < n; i++) if (!was[i]) {
      wasBad = wasEdge = false;
      dfs(i);
      if (!wasEdge && i != 0) continue;

      if (!wasBad) goodCnt++;
      else badCnt++;
    }

    if (badCnt + goodCnt > 1)
      need += goodCnt;
    printf("%d\n", need);
  }
  return 0;
}