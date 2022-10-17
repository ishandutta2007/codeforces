#include <algorithm>
#include <bits/stdc++.h>
#include <cwchar>
#include <iterator>
#include <queue>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], b[N], c[N];
int ans;
int p[N];

int cnt[3];

bool OK;
int K;

priority_queue<pii> stl[3], str[3];

bool cmp(int i, int j) { return b[i] < b[j]; }

void check(int x, int y, int z) {
  if (stl[x].size() < K)
    return;
  if (str[y].size() < K)
    return;
  int a = stl[x].top().f;
  int b = -str[y].top().f;
  OK |= (a < b && cnt[z] >= K);
}
void lol1() {
  for (int i = 0; i < 3; i++) {
    cnt[i] = n / 3;
    while (!stl[i].empty())
      stl[i].pop();
    while (!str[i].empty())
      str[i].pop();
  }
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && b[p[i]] == b[p[j]])
      j++;
    for (int q = i; q < j; q++) {
      stl[c[p[q]]].push({a[p[q]], q});
      str[c[p[q]]].push({-a[p[q]], q});
      cnt[c[p[q]]]--;
    }
    for (int q = 0; q < 3; q++) {
      while (stl[q].size() > K)
        stl[q].pop();
      while (str[q].size() > K)
        str[q].pop();
    }
    check(0, 1, 2);
    check(0, 2, 1);
    check(1, 0, 2);
    check(1, 2, 0);
    check(2, 0, 1);
    check(2, 1, 0);
  }
}
void lol2(int x, int y, int z) {
  for (int i = 0; i < 3; i++)
    cnt[i] = K;

  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && b[p[i]] == b[p[j]])
      j++;
    if (cnt[x] > 0)
      for (int q = i; q < j; q++)
        if (c[p[q]] == x)
          cnt[x]--;
    if (cnt[y] > 0 && cnt[x] == 0)
      for (int q = i; q < j; q++)
        if (c[p[q]] == y)
          cnt[y]--;
    if (cnt[z] > 0 && cnt[y] == 0 && cnt[x] == 0)
      for (int q = i; q < j; q++)
        if (c[p[q]] == z)
          cnt[z]--;
  }
  bool ok = 1;
  for (int i = 0; i < 3; i++)
    if (cnt[i])
      ok = 0;
  OK |= ok;
}
void lol2() {
  lol2(0, 1, 2);
  lol2(0, 2, 1);
  lol2(1, 0, 2);
}
void kek() {
  lol1();
  lol2();
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    // a[i] = rand(), b[i] = rand(), c[i] =  i % 3 + 1;
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (int i = 0; i < n; i++)
    c[i]--;
  for (int i = 0; i < n; i++)
    p[i] = i;

  int l = 1, r = n / 3;
  while (l <= r) {
    int m = (l + r) >> 1;
    K = m;
    OK = 0;

    sort(p, p + n, cmp);
    kek();
    for (int i = 0; i < n; i++)
      b[i] = -b[i];
    reverse(p, p + n);
    kek();

    for (int i = 0; i < n; i++)
      swap(a[i], b[i]);

    sort(p, p + n, cmp);
    kek();
    for (int i = 0; i < n; i++)
      b[i] = -b[i];
    reverse(p, p + n);
    kek();

    if (OK)
      l = m + 1;
    else
      r = m - 1;
  }
  printf("%d\n", 3 * (l - 1));
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}