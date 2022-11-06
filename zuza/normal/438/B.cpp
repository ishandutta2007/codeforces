#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

struct Edge {
  int a, b;
};

const int MAXN = 1e5 + 123;

vector<Edge> E[MAXN];

int up[MAXN];
int find_dad(int x) {
  if (up[x] == -1) return x;
  return up[x] = find_dad(up[x]);
}

int w[MAXN];

int main(void)
{
  int n, e; scanf("%d %d", &n, &e);
  vector<int> v_val(n);

  REP(i, n) scanf("%d", &v_val[i]);
  REP(i, n) w[i] = 1;

  REP(i, e) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back({a, b});
    E[b].push_back({b, a});
  }

  REP(i, n) up[i] = -1;

  vector<int> reps;
  vector<int> bio(n, false);
  REP(i, n) reps.push_back(i);
  sort(reps.begin(), reps.end(), [&](int a, int b) { return v_val[a] > v_val[b]; });

  double ans = 0;
  for (int r : reps) {
    bio[r] = true;
    assert(find_dad(r) == r);

    for (auto e : E[r]) {
      int B = find_dad(e.b);
      if (B != r && bio[B]) {
        ans += w[r] * (double)w[B] * v_val[r];
        w[r] += w[B];
        up[B] = r;
      }
    }
  }

  printf("%.8lf\n", 2*ans / n / (n-1));
  return 0;
}