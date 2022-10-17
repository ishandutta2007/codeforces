#include<bits/stdc++.h>
using namespace std;

int T,n,cnt[101];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        int ans=0;
        for(int i=1;i<=100;i++)
            ans=max(ans,cnt[i]);
        printf("%d\n",ans);
    }
}