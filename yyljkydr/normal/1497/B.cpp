#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],m,cnt[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=m;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),cnt[a[i]%m]++;
        int ans=0;
        for(int i=0;i<=m/2;i++)
        {
            if(cnt[i]||cnt[m-i])
            {
                ans++;
                if(i!=m-i&&i!=0)
                {
                    ans+=max(0,max(cnt[i],cnt[m-i])-min(cnt[i],cnt[m-i])-1);
                }
            }
        }
        printf("%d\n",ans);
    }
}