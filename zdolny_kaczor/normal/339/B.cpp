# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long dist = 0;
  int where = 1;
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    if (x >= where) {
      dist += x - where;
    }
    else 
      dist += n - (where - x);
    where = x;
  }
  printf("%lld\n", dist);
}