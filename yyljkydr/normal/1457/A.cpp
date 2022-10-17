#include<bits/stdc++.h>
using namespace std;

int T,n,m,r,c;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&r,&c);
        int ans=0;
        ans=max(r-1,n-r)+max(c-1,m-c);
        printf("%d\n",ans);
    }
}