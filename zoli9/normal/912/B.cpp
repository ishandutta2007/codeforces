#include <bits/stdc++.h>
using namespace std;
unsigned long long n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    unsigned long long cc=0;
    while(n>0)
    {
        n/=2;
        cc++;
    }
    unsigned long long ans=((long long)1<<(cc));
    cout<<ans-1<<endl;
    return 0;
}