#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,a[maxn];
LL u,v;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%lld%lld",&n,&u,&v);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        bool flag=1;
        for (int i=1;i<n;++i)
            flag&=abs(a[i]-a[i+1])<=1;
        
        if (!flag)
            puts("0");
        else    {
            LL ans=2e9;
            for (int i=1;i<n;++i)
                if (abs(a[i]-a[i+1])==1)
                    ans=min(ans,min(u,v));
                else
                    ans=min(ans,v+min(u,v));
            printf("%lld\n",ans);
        }
    }
    return 0;
}