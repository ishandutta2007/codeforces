#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define TASKNAME "std"
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

class Automaton {
  struct Node {
    int ne[26];
    int suf;
    
    public:
    Node() : suf(0) { memset(ne, -1, sizeof ne); }
    int& operator[](int c) { return ne[c]; }
  };

  vector<Node> ns;
  vb term;
  int last;
  
  void printAll(int v, const string &cur) {
    if (term[v]) eprintf("|%s|\n", cur.c_str());
    if (!was[v]) {
      was[v] = true;
      eprintf("%d: (-->%d)", v, ns[v].suf);
      for (int i = 0; i < 26; i++)
        if (ns[v][i] >= 0)
          eprintf(" --%c-->%d", 'a' + i, ns[v][i]);
      eprintf("\n");
    }
    
    for (int i = 0; i < 26; i++)
      if (ns[v][i] >= 0)
        printAll(ns[v][i], cur + string(1, 'a' + i));
  }
  
  vi ord;
  vb was;
  void calcOrd(int v) {
    if (was[v]) return;
    was[v] = true;
    for (int i = 0; i < 26; i++)
      if (ns[v][i] >= 0)
        calcOrd(ns[v][i]);
    ord.pb(v);
  }
 
  public:
  Automaton() : ns(1), last(0) { ns[0].suf = -1; }
  void append(int c) {
    assert('a' <= c && c <= 'z');
    c -= 'a';
    
    int cur = sz(ns);
    ns.pb(Node());
    
    for (int v = last; v >= 0; v = ns[v].suf) {
      if (ns[v][c] < 0) {
        ns[v][c] = cur;
        continue;
      }
      int p = ns[v][c];
      int p2 = sz(ns);
      ns.pb(ns[p]);
      ns[p2].suf = ns[p].suf;
      ns[p].suf = p2;

      for (int v2 = v; v2 >= 0 && ns[v2][c] == p; v2 = ns[v2].suf)
        ns[v2][c] = p2;
      ns[cur].suf = p2;
      break;
    }
    last = cur;
  }
  void printAll() {
    term = vb(sz(ns), false);
    for (int v = last; v >= 0; v = ns[v].suf)
      term[v] = true;
    was = vb(sz(ns), false);
    printAll(0, "");
  }
  
  ll solve() {
    int n = sz(ns);
    ord.clear();
    was = vb(n, false);
    calcOrd(0);
    reverse(ord.begin(), ord.end());
    
    int m = sz(ord);
    assert(ord[m - 1] == last);
    
    vll cnt(n, 0);
    for (int v = last; v >= 0; v = ns[v].suf)
      cnt[v]++;
      
    for (int i = m - 1; i >= 0; i--) {
      int v = ord[i];
      for (int i2 = 0; i2 < 26; i2++) if (ns[v][i2] >= 0)
        cnt[v] += cnt[ns[v][i2]];
    }
    
    vll diffCnt(n, 0);
    diffCnt[0] = 1;
    for (int i = 0; i < m; i++) {
      int v = ord[i];
      for (int i2 = 0; i2 < 26; i2++) if (ns[v][i2] >= 0)
        diffCnt[ns[v][i2]] += diffCnt[v];
    }
    
    ll ans = 0;
    for (int i = 1; i < n; i++) {
//      eprintf("%I64d %I64d\n", diffCnt[i], cnt[i]);
      ans += diffCnt[i] * (cnt[i] * (cnt[i] + 1));
    }
    return ans / 2;
  }
};

const int MAXL = 1e5 + 1e3;

char s[MAXL + 1];
int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1)  {
    Automaton a;
    for (int i = 0; s[i]; i++) {
      a.append(s[i]);
    }
//    a.printAll();
    ll ans = a.solve();
    printf("%I64d\n", ans);
  }
  return 0;
}