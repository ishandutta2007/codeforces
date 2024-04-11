#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,ans=0;
        scanf("%d",&n);
        for (int s=2;s*s+(s-1)*(s-1)<=n;++s)
            ++ans;
        printf("%d\n",ans);
    }
    return 0;
}