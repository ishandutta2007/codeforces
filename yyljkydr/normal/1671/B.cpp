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
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int tot=0;
        for(int i=2;i<=n;i++)
            tot+=a[i]-a[i-1]-1;
        puts(tot<=2?"YES":"NO");
    }
}