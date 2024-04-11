#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int a[N];

int ans[2][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long k;
        scanf("%lld",&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int mx=*max_element(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            ans[0][i]=mx-a[i];
        mx=*max_element(ans[0]+1,ans[0]+n+1);
        for(int i=1;i<=n;i++)
            ans[1][i]=mx-ans[0][i];
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[1^(k&1)][i]," \n"[i==n]);
    }
}