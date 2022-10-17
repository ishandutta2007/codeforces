#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),sum+=a[i];
        if(sum<n)
            puts("1");
        else if(sum==n)
            puts("0");
        else if(sum>n)
            printf("%lld\n",sum-n);
    }
}