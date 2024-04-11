#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 500000 + 10, MOD = 1e9 + 7;
const LL inf = 1ll << 60;

map<int, int> Xs, Ys;
char s[MAXN];
LL xt[MAXN], yt[MAXN];
int n, h, w;
int dx, dy;
int minDx, maxDx;
int minDy, maxDy;

LL solve(int x, int dx, int minDx, int maxDx, int h, map<int, int> &Xs) {
  LL ret = inf;
  if (dx > 0) {
    if (x + maxDx > h) ret = min(ret, (LL)Xs[h - x + 1]);
    else {
      int k = (h - maxDx - x) / dx;
      while (x + k * dx + maxDx <= h) ++ k;
      assert(k >= 1);
      int rx = h - x - k * dx + 1;
      ret = min(ret, Xs[rx] + (LL)k * n);
    }
  }
  if (dx < 0) {
    if (x + minDx < 1) ret = min(ret, (LL)Xs[-x]);
    else {
      int k = (-x - minDx) / dx;
      while (x + k * dx + minDx > 0) ++ k;
      assert(k >= 1);
      int rx = -dx * k - x;
      ret = min(ret, Xs[rx] + (LL)k * n);
    }
  }
  if (x + maxDx > h) ret = min(ret, (LL)Xs[h - x + 1]);
  if (x + minDx < 1) ret = min(ret, (LL)Xs[-x]);
  return ret; 
}

int main() {
  scanf("%d%d%d", &n, &h, &w);
  scanf("%s", s);
  dx = 0, dy = 0;
  minDx = minDy = 0;
  maxDx = maxDy = 0;
  Xs[0] = Ys[0] = 0;
  for (int i = 0; s[i]; ++ i) {
    if (s[i] == 'U') -- dx;
    else if (s[i] == 'D') ++ dx;
    else if (s[i] == 'L') -- dy;
    else if (s[i] == 'R') ++ dy;
    if (!Xs.count(dx)) Xs[dx] = i + 1;
    if (!Ys.count(dy)) Ys[dy] = i + 1;
    minDx = min(minDx, dx);
    minDy = min(minDy, dy);
    maxDx = max(maxDx, dx);
    maxDy = max(maxDy, dy);
  }
  for (int x = 1; x <= h; ++ x) {
    xt[x - 1] = solve(x, dx, minDx, maxDx, h, Xs);
    //cout << xt[x - 1] << " ";
  }
  //cout << endl;
  for (int y = 1; y <= w; ++ y) {
    yt[y - 1] = solve(y, dy, minDy, maxDy, w, Ys);
    //cout << yt[y - 1] << " ";
  }
  //cout << endl;
  sort(xt, xt + h);
  sort(yt, yt + w);
  int sy(0);
  int ret(0);
  if (xt[h - 1] == inf && yt[w - 1] == inf) {
    cout << "-1" << endl;
    return 0;
  }
  for (int x = 0, y = 0; x < h; ++ x) {
    while (y < w && yt[y] <= xt[x]) {
      sy += yt[y] % MOD; sy %= MOD;
      ++ y;
    }
    xt[x] %= MOD;
    ret += (sy + (LL)(w - y) * xt[x] % MOD) % MOD;
    ret %= MOD;
  }
  cout << ret << endl;
  return 0;
}