#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

const ll INFLL = ll(1e18);

class min_stack {
public:
  min_stack() : data(1, mp(INFLL, INFLL)) {}
  void push_back(ll x) {
    data.emplace_back(x, min(x, getMin()));
  }
  ll pop_back() {
    ll res = data.back().first;
    data.pop_back();
    return res;
  }
  bool empty() const { return sz(data) == 1; }
  ll getMin() const { return data.back().second; }
private:
  vector<pair<ll, ll>> data;
};

void check_min_stack() {
  min_stack m;
  assert(m.empty());
  assert(m.getMin() == INFLL);
  m.push_back(10);
  assert(!m.empty());
  assert(m.getMin() == 10);
  m.push_back(20);
  assert(!m.empty());
  assert(m.getMin() == 10);
  m.push_back(5);
  assert(!m.empty());
  assert(m.getMin() == 5);
  m.push_back(6);
  assert(!m.empty());
  assert(m.getMin() == 5);
  m.pop_back();
  assert(!m.empty());
  assert(m.getMin() == 5);
  m.push_back(6);
  assert(!m.empty());
  assert(m.getMin() == 5);
  m.pop_back();
  assert(!m.empty());
  assert(m.getMin() == 5);
  m.pop_back();
  assert(!m.empty());
  assert(m.getMin() == 10);
  m.pop_back();
  assert(!m.empty());
  assert(m.getMin() == 10);
  m.pop_back();
  assert(m.empty());
  assert(m.getMin() == INFLL);
}

class min_queue {
public:
  void push_back(ll x) {
    r.push_back(x);
  }
  void pop_front() {
    if (l.empty()) {
      while (!r.empty()) {
        l.push_back(r.pop_back());
      }
    }
    assert(!l.empty());
    l.pop_back();
  }
  ll getMin() const { return min(l.getMin(), r.getMin()); }
private:
   min_stack l, r;
};

void check_min_queue() {
  deque<int> data;
  min_queue q;
  for (int i = 0; i < 100000; i++) {
    if (sz(data) > 1 && rand() & 1) {
      data.pop_front();
      q.pop_front();
    } else {
      int x = rand() % 10;
      data.push_back(x);
      q.push_back(x);
    }
    assert(*min_element(data.begin(), data.end()) == q.getMin());
  }
}

class Magic {
public:
  void push_back(ll change) {
    lastPos += change;
    poses.push_back(lastPos);
    minPoses.push_back(lastPos);
  }
  void pop_front() {
    assert(!poses.empty());
    curZero = poses.front();
    poses.pop_front();
    minPoses.pop_front();
  }

  ll getSumChange() const {
    return lastPos - curZero;
  }
  ll getMinVal() const {
    return minPoses.getMin() - curZero;
  }

private:
  ll curZero = 0;
  ll lastPos = 0;
  deque<ll> poses;
  min_queue minPoses;
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  check_min_stack();
  check_min_queue();

  int n, a, b, c, d, start, len;
  while (scanf("%d%d%d%d%d%d%d", &n, &a, &b, &c, &d, &start, &len) == 7) {
    vector<pii> evs(n);
    for (pii &e : evs)
      scanf("%d%d", &e.first, &e.second);
    sort(evs.begin(), evs.end());

    vi ts;
    ts.push_back(0);
    for (pii &e : evs) {
      ts.push_back(e.first + 1);
      if (e.first >= len) {
        ts.push_back(e.first - len + 1);
      }
    }
    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end());

    Magic before, inside, after;
    auto check = [&]() {
      ll off = start;
      if (off + before.getMinVal() < 0) return false;
      off += before.getSumChange();
      assert(off >= 0);

      if (off + inside.getMinVal() < 0) return false;
      off += inside.getSumChange();
      assert(off >= 0);
      return true;
    };

    int pinside = 0, pafter = 0;
    for (int i = 0; i < n; i++) {
      after.push_back(evs[i].second == 1 ? +a : -b);
    }
    for (int t : ts) {
      while (pafter < n && evs[pafter].first < t + len) {
        inside.push_back(evs[pafter].second == 1 ? +c : -d);
        after.pop_front();
        pafter++;
      }
      while (pinside < n && evs[pinside].first < t) {
        before.push_back(evs[pinside].second == 1 ? +a : -b);
        inside.pop_front();
        pinside++;
      }
//      eprintf("t=[%d..%d), pinside=%d, pafter=%d\n", t, t + len, pinside, pafter);
      if (check()) {
        printf("%d\n", t);
        goto end;
      }

    }
    printf("-1\n");
    end:;
  }

  return 0;
}