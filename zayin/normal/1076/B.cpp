#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n;
    cin>>n;
    for (LL i=2;i*i<=n;++i)
    {
        if (n%i)    continue;
        cout<<(n-i)/2+1<<endl;
        return 0;
    }
    puts("1");
    return 0;
}