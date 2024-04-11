#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
vector<LL> A;

int main()
{
    scanf("%lld",&n);
    for (LL i=1;i*i<=n;++i)
    {
        if (n%i)    continue;
        LL t=n/i;
        // cout<<i<<" "<<(t-1)*t/2LL*i+t<<endl;
        A.push_back((t-1)*t/2LL*i+t);
        if (i*i==n) continue;
        // cout<<t<<" "<<(i-1)*i/2LL*t+i<<endl;
        A.push_back((i-1)*i/2LL*t+i);
    }
    sort(A.begin(),A.end());
    for (LL x:A)
        printf("%lld ",x);
    return 0;
}