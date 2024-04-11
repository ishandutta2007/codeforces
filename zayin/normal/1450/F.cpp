#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,a[maxn];

int cnt[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) cnt[i]=0;
        for (int i=1;i<=n;++i)
            scanf("%d",a+i),++cnt[a[i]];
        
        int mx=0;
        for (int i=1;i<=n;++i)
            mx=max(mx,cnt[i]);
        
        if (mx>(n+1)/2)
            puts("-1");
        else    {
            int ans=1;
            for (int i=1;i<=n;++i) cnt[i]=0;
            ++cnt[a[1]],++cnt[a[n]];
            for (int i=1;i<=n;++i)  {
                if (i<n&&a[i]==a[i+1])
                    ++ans,++cnt[a[i]],++cnt[a[i+1]];
            }
            int mx=0;
            for (int i=1;i<=n;++i)
                mx=max(mx,cnt[i]);
            
            int val=ans-mx;
            // cout<<ans<<" "<<mx<<" ~ "<<val<<endl;
            if (val>=-1)
                printf("%d\n",ans-1);
            else
                printf("%d\n",(ans-1)-1-val);
        }
    }
    return 0;
}