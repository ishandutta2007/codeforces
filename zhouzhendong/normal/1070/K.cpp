#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,k,a[N],sum,cur,ans[N],num,cnt;
int main() {
  scanf("%d%d",&n,&k);
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]), sum += a[i];
  if (sum % k) return puts("No"), 0;
  sum /= k;
  for (int i = 1 ; i <= n ; ++ i) {
    ++ num;
    cur += a[i];
    if (cur > sum) return puts("No"), 0;
    if (cur == sum) {
      ans[++cnt] = num;
      cur = 0;
      num = 0;
    }
  }
  puts("Yes");
  for (int i = 1 ; i <= k ; ++ i)
    printf("%d ",ans[i]);
  puts("");
  return 0;
}