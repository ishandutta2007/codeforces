#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

long long h[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long ans=0,sum=0;;
        bool ok=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&h[i]),ans+=h[i];
            sum+=i-1;
            if(sum>ans)
                ok=1;
        }
        if(!ok)
            puts("YES");
        else
            puts("NO");
    }
}