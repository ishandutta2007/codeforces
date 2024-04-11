#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,x;

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        int odd=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            odd+=(a[i]&1);
        }
        if(x==n)
            puts(odd&1?"YES":"NO");
        else if(odd&&(n-odd))
            puts("YES");
        else if((x%2==1)&&odd)
            puts("YES");
        else
            puts("NO");
    }
}