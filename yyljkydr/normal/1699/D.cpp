#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int T,n,f[N],a[N],cnt[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n+1;i++)
        {
            f[i]=-1e9;
            int mx=0;
            for(int j=i-1;j>=0;j--)
            {
                if((i-j-1)&1)
                {
                    cnt[a[j]]++;
                    mx=max(mx,cnt[a[j]]);
                    continue;
                }
                if(i!=n+1&&j!=0&&a[i]!=a[j])
                {
                    cnt[a[j]]++;
                    mx=max(mx,cnt[a[j]]);
                    continue;
                }
                if(mx*2>i-j-1)
                {
                    cnt[a[j]]++;
                    mx=max(mx,cnt[a[j]]);
                    continue;
                }
                f[i]=max(f[i],f[j]+1);
                cnt[a[j]]++;
                mx=max(mx,cnt[a[j]]);
            }
            for(int j=i-1;j>=0;j--)
                cnt[a[j]]--;
        }
        printf("%d\n",f[n+1]-1);
    }
}