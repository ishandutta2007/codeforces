#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

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

struct Ev {
  int t, v, id;
  Ev() { t = v = id = -1; }
  Ev(int _t, int _id, int _v) : t(_t), v(_v), id(_id) {}
  bool operator<(const Ev &e2) const { return t < e2.t; }
};

int getOrder(int a, int b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}

int main() {
  int n, s;
  while (scanf("%d%d", &n, &s) >= 2) {
    vector<vector<pii> > cs(n);
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      cs[i] = vector<pii>(k);
      for (int i2 = 0; i2 < k; i2++) scanf("%d%d", &cs[i][i2].first, &cs[i][i2].second);
    }
    int ans = 0;
    for (int a = 0; a < n; a++)
      for (int b = a + 1; b < n; b++) {
	if (a == b) continue;
	vector<Ev> evs;
	int ct = 0;
	for (int i = 0; i < cs[a].size(); i++) evs.pb(Ev(ct, 0, cs[a][i].first)), ct += cs[a][i].second;
	evs.pb(Ev(ct, 0, 0));
	
	ct = 0;
	for (int i = 0; i < cs[b].size(); i++) evs.pb(Ev(ct, 1, cs[b][i].first)), ct += cs[b][i].second;
	sort(evs.begin(), evs.end());
	evs.pb(Ev(ct, 1, 0));
	
	int p[] = { 0, 0 };
	int v[] = { 0, 0 };
	int pt = 0;
	for (int i = 0; i < evs.size(); i++) {
	  eprintf("ev: t=%d, id=%d, v=%d\n", evs[i].t, evs[i].id, evs[i].v);
	  int dt = evs[i].t - pt;
	  int o1 = getOrder(p[0], p[1]);
	  eprintf("  dt=%d. p1=%d, p2=%d. o1=%d\n", dt, p[0], p[1], o1);
	  p[0] += v[0] * dt;
	  p[1] += v[1] * dt;
	  v[evs[i].id] = evs[i].v;
	  int o2 = getOrder(p[0], p[1]);
	  eprintf("        p1=%d, p2=%d. o2=%d\n", p[0], p[1], o2);
	  if (pt && (evs[i].v || o2)) {
	    if (o1 * o2 < 0 || (o1 && !o2)) {
	      eprintf("        ans++\n");
	      ans++;
	    }
	  }
	  pt = evs[i].t;
	}
      }
    printf("%d\n", ans);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}