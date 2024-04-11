#include <iostream>

using namespace std;

int main()
{
    int T; cin>>T;
    while(T--)
    {
        long long int s,a,b,c; cin>>s>>a>>b>>c;
        long long int ans=s/c;
        ans+=(ans/a)*b;
        cout<<ans<<endl;
    }
    return 0;
}