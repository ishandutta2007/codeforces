#include <iostream>

using namespace std;

int main()
{
    int T; cin>>T;
    while(T--)
    {
        long long int a,b,k; cin>>a>>b>>k;
        long long int ans=0;
        ans+=(a-b)*(k/2);
        ans+=a*(k%2);
        cout<<ans<<endl;
    }
    return 0;
}