#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
          scanf("%d%d",&n,&k);
          bool flag = true;
          for(int i =  1;i <= n;i++) scanf("%d",a + i);
          sort(a + 1, a + 1 + n);
          long long ans = 0;
          for(int i = 2;i <= n;i++){
                    if((a[i] - a[1]) % k) flag = false;
                    else ans += (a[i] - a[1]) / k;
          }
          if(flag)printf("%I64d\n",ans);
          else printf("-1\n");
          return 0;
}