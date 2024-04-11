#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1048576 << 1;

struct Node {
  int l, r, i;
  bool operator < (Node &rhs) const {
    return r < rhs.r;
  }
};

Node Q[MAXN];
vector<Node> E[1030];
int a[MAXN], num[MAXN];
LL ans[MAXN];

int main(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &a[i]);
    a[i] = a[i] ^ a[i - 1];
  }
  for (int i = 1; i <= m; ++ i){
    scanf("%d%d", &Q[i].l, &Q[i].r);
    Q[i].l --; Q[i].i = i;
  }
  int x = n / (int)(sqrt(n)) + 1;
  int y = sqrt(n);
  for (int i = 1; i <= m; ++ i){
    E[Q[i].l / y].push_back(Q[i]);
  }
  for (int i = 0; i < x; ++ i) {
    sort(E[i].begin(), E[i].end());
  }
  int L = 0, R = 0;
  long long now = 0; num[0] = 1;
  for (int i = 0; i < x; ++ i) {
    for (int j = 0; j < E[i].size(); ++ j) {
      Node w = E[i][j];
      while (R < w.r) {
        now += num[k ^ a[++ R]];
        num[a[R]] ++;	
      }
      while (R > w.r) {
        num[a[R]] --;
        now -= num[k ^ a[R --]];
      }
      while (L < w.l) {
        num[a[L]] --;
        now -= num[k ^ a[L ++]];
      }
      while (L > w.l) {
        now += num[k ^ a[-- L]];
        num[a[L]] ++;
      }
      ans[w.i] = now;
    }
  }
  for (int i = 1; i <= m; ++ i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}