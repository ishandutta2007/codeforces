#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

struct Event {
  int x;
  int y1, y2;
  int add;
    
  friend bool operator < (const Event& a, const Event& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.add > b.add;
  }
};

const int inf = 1e9;

struct Node {
  int maks;
  int maks_pos;
  int push_add;

  Node() { maks = -inf; maks_pos = -inf; push_add = 0; }

  void add(int delta, int height) {
    push_add += delta;
    maks += delta;
  }
  void propagate(Node& a, Node& b, int height) {
    if (push_add != 0) {
      a.add(push_add, height-1);
      b.add(push_add, height-1);
      push_add = 0; 
    }
  }
  void validate(Node& a, Node& b, int height) {
    maks = max(a.maks, b.maks);
    if (maks == a.maks) maks_pos = a.maks_pos;
    else maks_pos = b.maks_pos;
  }
};

struct Tournament {
  int n, offset;
  vector<Node> data;

  Tournament(int n) : n(n) {
    offset = 2; while (offset < n) offset *= 2; // radi i ako je offset = 1, al nekako mi je ugodnije ovo
    data.resize(2*offset);
  }

  void validate_one(int x, int height) { data[x].validate(data[2*x], data[2*x+1], height); }
  void validate_all(int l, int r, int height) {
    if (l == 0) return;
    validate_one(l/2, height+1);
    validate_one((r-1)/2, height+1);
    validate_all(l/2, (r+1)/2, height+1);
  }
  void prop_one(int x, int height) { data[x].propagate(data[2*x], data[2*x+1], height); }
  void prop_all(int l, int r, int height) {
    if (l == 0) return;
    prop_all(l/2, (r+1)/2, height+1);
    prop_one(l/2, height+1);
    prop_one((r-1)/2, height+1);
  }

  void update(int L, int R, int delta) { // [L, R)
    L += offset; R += offset;
    prop_all(L, R, 0);
    for (int height = 0, l = L, r = R; l < r; ++l>>=1, r>>=1, ++height) {
      if (l&1) data[l].add(delta, height);
      if (r&1) data[r-1].add(delta, height);
    }
    prop_all(L, R, 0);
    validate_all(L, R, 0);
  }

  void init() {
    for (int i = 0; i < n; ++i) {
      data[i+offset].maks_pos = i;
      data[i+offset].maks = 0;
    }
    for (int i = offset-1; i >= 1; --i)
      validate_one(i, 0); // height nije dobar!
  }
}; // "r-l" shouldn't appear (instead of "r-1")


int main(void)
{
  int n; scanf("%d", &n);
  vector<Event> events;
  Tournament T(3e5 + 123);

  const int MAXN = 1e5 + 123;
  static int inL[MAXN], inV[MAXN], inR[MAXN];
  REP(i, n) {
    int l, v, r; scanf("%d %d %d", &l, &v, &r);
    events.push_back({l, v, r, +1});
    events.push_back({v, v, r, -1});
    inL[i] = l;
    inV[i] = v;
    inR[i] = r;
  }
  sort(events.begin(), events.end());

  int maks = 0;
  int recon_L = -1, recon_R = -1;

  T.init();
  for (Event e : events) {
    T.update(e.y1, e.y2 + 1, e.add);
    int val = T.data[1].maks;
    if (val > maks) {
      maks = val;
      recon_L = e.x;
      recon_R = T.data[1].maks_pos;
    }
  }

  printf("%d\n", maks);
  vector<int> output;
  REP(i, n) if (inL[i] <= recon_L && recon_L <= inV[i] && inV[i] <= recon_R && recon_R <= inR[i]) output.push_back(i);
  assert((int)output.size() == maks);
  REP(i, maks) printf("%d%c", output[i]+1, i+1 == maks ? '\n' : ' ');
  return 0;
}