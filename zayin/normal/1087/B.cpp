#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n,k,ans=1LL<<60;
    cin>>n>>k;
    for (int d=1;d<k;++d)
    {
        if (n%d)    continue;
        ans=min(ans,(n/d)*k+d);
    }
    cout<<ans<<endl;
    return 0;
}