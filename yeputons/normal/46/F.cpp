#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef pair<int, int> pii;

class dss {
  vi par, szs;
  
  public:
    dss(int sz) {
      par = vi(sz);
      szs = vi(sz, 1);
      for (int i = 0; i < sz; i++) par[i] = i;
    }
    
    int get(int x) {
      if (par[x] == x) return x;
      return par[x] = get(par[x]);
    }
    
    void merge(int a, int b) {
      a = get(a); b = get(b);
      if (szs[a] > szs[b]) {
        par[b] = a;
        szs[a] += szs[b]; 
      } else {
        par[a] = b;
        szs[b] += szs[a];
      }
    }
};

struct Edge {
  int b, id;
  Edge() {}
  Edge(int _b, int _id) : b(_b), id(_id) {}
};

char buf[1024];
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 2) {
    vector<vector<Edge> > es(n);
    vector<pii> pes(m);
    for (int i = 0; i < m; i++) {
      int a, b; scanf("%d%d", &a, &b), a--, b--;
      pes[i] = mp(a, b);
      es[a].pb(Edge(b, i));
      es[b].pb(Edge(a, i));
    }
    
    map<string, int> ids;
    vi owner(m, -1);
    vi pos(k, -1);
    for (int i = 0; i < k; i++) {
      int cnt;
      scanf("%s%d%d", buf, &pos[i], &cnt), pos[i]--;
      ids[buf] = i;
      for (int i2 = 0; i2 < cnt; i2++) {
        int key;
        scanf("%d", &key), key--;
        owner[key] = i;
      }
    }
    
    vi owner2(m, -1);
    vi pos2(k, -1);
    for (int i = 0; i < k; i++) {
      int cnt;
      scanf("%s", buf); int id = ids[buf];
      scanf("%d%d", &pos2[id], &cnt), pos2[id]--;
      for (int i2 = 0; i2 < cnt; i2++) {
        int key;
        scanf("%d", &key), key--;
        owner2[key] = id;
      }
    }
    
    bool good = true;

    for (int step = 0; step < 2; step++) {
      vi open(m, false);
      dss comps(n);
      for (int i = 0; i < n; i++) {
        for (int i2 = 0; i2 < m; i2++) {
          if (open[i2]) continue;
          int c1 = comps.get(pos[owner[i2]]);
          if (c1 == comps.get(pes[i2].first) || c1 == comps.get(pes[i2].second)) {
            open[i2] = true;
            comps.merge(pes[i2].first, pes[i2].second);
          }
        }
      }
      
      for (int i = 0; i < k; i++)
        good = good && comps.get(pos[i]) == comps.get(pos2[i]);
      for (int i = 0; i < m; i++)
        good = good && comps.get(pos[owner[i]]) == comps.get(pos[owner2[i]]);
      
      swap(pos, pos2);
      swap(owner, owner2);
    }
    
    printf(good ? "YES\n" : "NO\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}