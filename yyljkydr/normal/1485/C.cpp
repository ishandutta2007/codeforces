#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+1e3+7;
 
typedef long long ll;
 
int T,a,b;
 
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        int t=2;
        long long ans=0;
        for(int i=1;(i-1)<a/(i+1)&&i<=b;i++)
            ans+=i-1,t=i;
        for(int i=t+2,j;i<=b+1;i=j+1)
        {
            if(a/i==0)
                break;
            j=min(b+1,a/(a/i));
            // j=i;
            ans+=1ll*a/i*(j-i+1);
            // ans+=min(a/(i+1),i-1);
        }
        // for(int i=1;i<=b;i++)
        //     ans+=min(a/(i+1),i-1);
        printf("%lld\n",ans);
    }
}