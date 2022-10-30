#include<bits/stdc++.h>
#define maxn 1000050
#define modu 998244353
using namespace std;
typedef long long LL;

LL n,m,a[maxn],b[maxn];

int main()  {
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;++i)  {
        scanf("%lld",a+i);
        if (a[i]>n-m)
            b[i]=1;
    }

    LL ans=1;
    for (int i=1,j=1;i<=n;i=j)  {

        if (b[i])
            ++i,++j;
        else    {
            // cout<<"i:"<<i<<endl;
            while (j<=n&&!b[j]) ++j;
            if (i==1||j>n) continue;
            ans=ans*(j-i+1)%modu;
            // cout<<"ppp:"<<i<<" "<<j<<endl;
        }

        // cout<<i<<" "<<j<<endl;
    }
    printf("%lld %lld\n",(n-m+1+n)*m/2,ans);

    return 0;
}