#include<bits/stdc++.h>
#define modu 998244353
using namespace std;
typedef long long LL;
int main()  {
    int n,m;
    LL ans=1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n+m;++i)
        ans=ans*2%modu;
    cout<<ans<<endl;
    return 0;
}