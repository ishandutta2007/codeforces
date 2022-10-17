#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long s=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s+=a[i];        
        if(s%n)
            puts("-1");
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                if(1ll*a[i]*n>s)
                    ans++;
            printf("%d\n",ans);
        }
    }
}