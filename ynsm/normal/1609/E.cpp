#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, K = 3;
const ll INF = 1e18;
/*
cbcbcbccbcbcbacacacacabababa
0 1 2
*/

int n, m;
string s;
int t[N << 2][K][K];

void upd(int v, int tl, int tr, int pos, int x) {
  if (tl == tr) {
    for (int i = 0; i < K; i++)
      for (int j = i; j < K; j++)
        t[v][i][j] = 1;
    if (x == 0)
      t[v][1][1] = t[v][2][2] = 0;
    if (x == 1)
      t[v][0][0] = t[v][2][2] = 0;
    if (x == 2)
      t[v][0][0] = t[v][1][1] = 0;
    return;
  }
  int tm = (tl + tr) >> 1;

  if (pos <= tm)
    upd(v << 1, tl, tm, pos, x);
  else
    upd(v << 1 | 1, tm + 1, tr, pos, x);
  for (int i = 0; i < K; i++)
    for (int j = i; j < K; j++)
      t[v][i][j] = inf;
  for (int i = 0; i < K; i++)
    for (int j = i; j < K; j++)
      for (int q = j; q < K; q++)
        for (int w = q; w < K; w++)
          t[v][i][w] = min(t[v][i][w], t[v << 1][i][j] + t[v << 1 | 1][q][w]);
}
void solve() {

  cin >> n >> m >> s;
  for (int i = 0; i < n; i++)
    upd(1, 1, n, i + 1, s[i] - 'a');

  while (m--) {
    int i;
    char x;
    cin >> i >> x;
    upd(1, 1, n, i, x - 'a');
    int ans = inf;
    for (int j = 0; j < K; j++)
      for (int q = j; q < K; q++)
        ans = min(ans, t[1][j][q]);
    printf("%d\n", ans);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}