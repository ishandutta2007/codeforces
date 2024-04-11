#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1e6 + 123;

vector<int> cdad;
vector<int> cdp;
vector<int> croot;

int v2c[MAXN];
int vnx[MAXN];

void repaint(int x, int ci) {
  while (x != -1) {
    v2c[x] = ci;
    x = vnx[x];
  }
}

void relax(int down, int up) {
  int down_c = v2c[down];
  int up_c = v2c[up];

  if (cdp[down_c] == cdp[up_c]) {
    int old_dp = cdp[down_c];
    int y = vnx[up];

    if (y != -1) {
      int nx_c = cdp.size();
      cdad.push_back(up);
      croot.push_back(y);
      cdp.push_back(cdp[up_c]);
      repaint(y, nx_c); // v2c

      cdp[up_c] = old_dp + 1;
      vnx[up] = -1;

      if (cdad[up_c] != -1) relax(croot[up_c], cdad[up_c]);
    } else {
      vnx[up] = down;
      repaint(down, up_c);
    }
  }

}

int main(void)
{
  int n; scanf("%d", &n);

  auto create = [&](int x, int dad) {
    int ci = cdp.size();

    cdad.push_back(dad);
    cdp.push_back(1);
    croot.push_back(x);

    v2c[x] = ci;
    vnx[x] = -1;
  };
  create(0, -1);

  FOR(i, 1, n+1) {

    int x; scanf("%d", &x); --x;
    create(i, x);
    relax(i, x);

    int rc = v2c[0];
    printf("%d%c", cdp[rc] - (vnx[0] == -1), i+1 == n+1 ? '\n' : ' ');
  }

  return 0;
}