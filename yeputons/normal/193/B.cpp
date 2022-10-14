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

const int MAXN = 30;
int n, u, r;
int as[MAXN],bs[MAXN],ks[MAXN],ps[MAXN],rps[MAXN];

int tmp[MAXN];
void perform(int *perm) {
  for (int i = 0; i < n; i++)
    tmp[i] = as[perm[i]];
  for (int i = 0; i < n; i++)
    as[i] = tmp[i];
}

ll ans;
void relax() {
  ll cans = 0;
  for (int i = 0; i < n; i++) cans += ks[i] * as[i];
  ans = max(ans, cans);
}

void go(int step, int prev = -1) {
  if (((u - step) & 1) == 0) {
    relax();
  }
  if (step >= u) return;

  perform(ps);
  for (int i = 0; i < n; i++) as[i] += r;
  go(step + 1, 0);
  for (int i = 0; i < n; i++) as[i] -= r;
  perform(rps);

  if (prev != 1) {
    for (int i = 0; i < n; i++) as[i] ^= bs[i];
    go(step + 1, 1);
    for (int i = 0; i < n; i++) as[i] ^= bs[i];
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d%d", &n, &u, &r) >= 1) {
    for (int i = 0; i < n; i++) scanf("%d", &as[i]);
    for (int i = 0; i < n; i++) scanf("%d", &bs[i]);
    for (int i = 0; i < n; i++) scanf("%d", &ks[i]);
    for (int i = 0; i < n; i++) scanf("%d", &ps[i]), ps[i]--, rps[ps[i]] = i;
    ans = -9e18;

    go(0);
    printf("%I64d\n", ans);
  }
  return 0;
}