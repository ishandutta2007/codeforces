#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n,c,q;

int mx[N];

signed main()
{
    scanf("%lld%lld",&n,&c);
    for(int i=1;i<=n;i++)
    {
        int c,d,h;
        scanf("%lld%lld%lld",&c,&d,&h);
        mx[c]=max(mx[c],d*h);
    }
    for(int i=1;i<=c;i++)
        for(int j=i;j<=c;j+=i)
            mx[j]=max(mx[j],mx[i]*j/i);
    for(int i=2;i<=c;i++)
        mx[i]=max(mx[i],mx[i-1]);
    scanf("%lld",&q);
    for(int i=1;i<=q;i++)
    {
        int d,h;
        scanf("%lld%lld",&d,&h);
        int x=upper_bound(mx+1,mx+c+1,d*h)-mx;
        printf("%lld%c",x>c?-1:x," \n"[i==q]);
    }
}