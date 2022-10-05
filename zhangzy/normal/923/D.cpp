#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5;

int n, m;
char s[maxn + 3], t[maxn + 3];
int cnt1[maxn + 3], cnt2[maxn + 3];
int lst1[maxn + 3], lst2[maxn + 3];

int main(void) {
  scanf("%s%s", s+1, t+1);
  n = strlen(s+1);
  m = strlen(t+1);
  for (int i = 1; i <= n; ++i) {
    cnt1[i] = cnt1[i-1] + (s[i] != 'A');
    lst1[i] = s[i] == 'A' ? lst1[i-1] : i;
  }
  for (int i = 1; i <= m; ++i) {
    cnt2[i] = cnt2[i-1] + (t[i] != 'A');
    lst2[i] = t[i] == 'A' ? lst2[i-1] : i;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    int a = r1 - max(l1-1, lst1[r1]), b = r2 - max(l2-1, lst2[r2]);
    int c = cnt1[r1] - cnt1[l1-1], d = cnt2[r2] - cnt2[l2-1];
    //printf("%d %d %d %d\n",a,b,c,d); 
    if (a < b) {
      putchar('0');
      continue;
    }
    if ((a - b) % 3) {
      c += 2;
    }
    if (c <= d && !(d - c & 1) && !(r1-l1+1==a&&d&&a==b) ) {
      putchar('1');
    } else {
      putchar('0');
    }
  }
  putchar('\n');
  return 0;
}