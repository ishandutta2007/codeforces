#include<bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int mx=max({a,b,c});
        int lb=max(0,mx-(a+b+c-mx)-1),rb=(a-1+b-1+c-1);
        int x;
        scanf("%d",&x);
        puts(lb<=x&&x<=rb?"YES":"NO");
    }
}