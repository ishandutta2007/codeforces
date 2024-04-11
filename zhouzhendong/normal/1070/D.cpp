#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long ll;
int a[N],k,n;
ll ans,cur;
int main() {
  scanf("%d%d",&n,&k);
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  cur = a[1];
  for (int i = 2 ; i <= n ; ++ i) {
    ans += (cur + k - 1) / k;
    if (cur % k != 0)
      cur = max(0ll,a[i] - (k - cur % k));
    else cur = a[i];
  }
  ans += (cur + k - 1) / k;
  cout << ans << endl;
  return 0;
}