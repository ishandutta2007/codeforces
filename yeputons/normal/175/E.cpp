#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

void relax(double &a, double b) { a = max(a, b); }
#define EPS (1e-9)

const double MINX = -1000;
double getSumTime(const vector<pair<double, int> > &evs, double r) {
  double res = 0;
  int cspd = 1;
  for (int i = 0; i < sz(evs); i++) {
    double x1 = evs[i].first;
    double x2 = r;
    if (i + 1 < sz(evs)) x2 = min(x2, evs[i + 1].first);

    if (x1 >= r - EPS) break;

    cspd += evs[i].second;
    res += cspd * (x2 - x1);
  }
  return res;
}
double getSumTime(const vector<pair<double, int> > &evs, double l, double r) {
  return getSumTime(evs, r) - getSumTime(evs, l);
}

const int MAXL = 13;
const int MAXN = 20;

double r1, r2, r3;
int d1, d2;

int fcnt[MAXL];

int sn1, sn2, sn3;

vector<pair<double, int> > evs;

double vs[MAXL][2];
double dyn[MAXL + 1][MAXN + 1][MAXN + 1];

double calcAns() {
  evs.clear();
  for (int i = 0; i < MAXL; i++) if (fcnt[i]) {
    evs.pb(mp(i - r3, fcnt[i]));
    evs.pb(mp(i + r3, -fcnt[i]));
  }
  evs.pb(mp(MINX, 0));
  sort(evs.begin(), evs.end());

  for (int i = 0; i < MAXL; i++) {
    vs[i][0] = getSumTime(evs, i - r1, i + r1) * d1;
    vs[i][1] = getSumTime(evs, i - r2, i + r2) * d2;
  }

  for (int i = 0; i <= MAXL; i++)
  for (int a = 0; a <= sn1; a++)
  for (int b = 0; b <= sn2; b++)
    dyn[i][a][b] = -1e100;

  dyn[0][sn1][sn2] = 0;
  for (int i = 0; i < MAXL; i++)
  for (int a = 0; a <= sn1; a++)
  for (int b = 0; b <= sn2; b++) if (dyn[i][a][b] > -EPS) {
    double cv = dyn[i][a][b];

    relax(dyn[i + 1][a][b], cv);

    if (fcnt[i] <= 1) {
      if (a) relax(dyn[i + 1][a - 1][b], cv + vs[i][0]);
      if (b) relax(dyn[i + 1][a][b - 1], cv + vs[i][1]);
    }
    if (fcnt[i] <= 0) {
      if (a >= 2) relax(dyn[i + 1][a - 2][b], cv + 2 * vs[i][0]);
      if (b >= 2) relax(dyn[i + 1][a][b - 2], cv + 2 * vs[i][1]);
      if (a && b) relax(dyn[i + 1][a - 1][b - 1], cv + vs[i][0] + vs[i][1]);
    }
  }
  return dyn[MAXL][0][0];
}

double ans;
void go(int pos, int n3) {
  if (!n3) {
    bool g = true;
    for (int i = 0; i < MAXL; i++)
      if (fcnt[i] > fcnt[MAXL - i - 1]) { g = false; break; }
      else if (fcnt[i] < fcnt[MAXL - i - 1]) break;
    if (!g) return;
    ans = max(ans, calcAns());
    return;
  }
  if (pos >= MAXL) return;

  for (int i = 0; i <= 2 && i <= n3; i++) {
    fcnt[pos] = i;
    go(pos + 1, n3 - i);
  }
  fcnt[pos] = 0;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d%d", &sn1, &sn2, &sn3) >= 1) {
    scanf("%lf%lf%lf", &r1, &r2, &r3);
    if (fabs(r1 - 1) < EPS) r1 = 0; else r1 = sqrt(r1 * r1 - 1);
    if (fabs(r2 - 1) < EPS) r2 = 0; else r2 = sqrt(r2 * r2 - 1);
    if (fabs(r3 - 1) < EPS) r3 = 0; else r3 = sqrt(r3 * r3 - 1);

    scanf("%d%d", &d1, &d2);

    ans = 0;
    go(0, sn3);
    printf("%.18e\n", ans);
  }
  return 0;
}