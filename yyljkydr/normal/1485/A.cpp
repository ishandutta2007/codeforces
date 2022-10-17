#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+1e3+7;
 
int T;
 
long long a,b;
 
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&a,&b);
        long long ans=1e9;
        if(b!=1)
        {
            long long x=a,t=0;
            while(x!=0)
                x/=b,t++;
            ans=min(ans,t);
        }
        for(long long y=b+1;(y-1)*(y-1)<=a;y++)
        {
            long long x=a,t=0;
            while(x!=0)
                x/=y,t++;
            ans=min(ans,y-b+t);
        }
        if(a>=b)
            ans=min(ans,a+1-b+1);
        printf("%lld\n",ans);
    }
}