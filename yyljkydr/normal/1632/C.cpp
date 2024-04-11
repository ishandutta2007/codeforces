#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=b-a;
        for(int i=a;i<=b;i++)
            ans=min(ans,(i|b)-b+i-a+1);
        for(int i=b;i<=b*2;i++)
            ans=min(ans,(a|i)-b+1);
        printf("%d\n",ans);
    }
}