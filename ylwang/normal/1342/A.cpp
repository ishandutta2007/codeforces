#include<iostream>
#include<cstdio>
using namespace std;
int T,n,x,y,a,b;
long long ans1,ans2;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        ans1=1ll*a*x+1ll*a*y;
        ans2=1ll*b*x+1ll*a*(y-x);
        printf("%lld\n",min(ans1,ans2));
    }
    return 0;
}