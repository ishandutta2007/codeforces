#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N],l,r;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&l,&r);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int L=lower_bound(a+1,a+n+1,l-a[i])-a;
            int R=upper_bound(a+1,a+n+1,r-a[i])-a-1;
            if(R>=max(L,i+1))
                ans+=R-max(L,i+1)+1;
        }
        printf("%lld\n",ans);
    }
}