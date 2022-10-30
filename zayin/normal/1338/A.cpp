#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,a[maxn];

int Log2(int x) {   return !x?0:Log2(x>>1)+1;  }

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        int mx=-1e9,ans=0;
        for (int i=1;i<=n;++i)  {
            mx=max(mx,a[i]);
            ans=max(ans,Log2(mx-a[i]));
        }
        printf("%d\n",ans);
    }
    return 0;
}