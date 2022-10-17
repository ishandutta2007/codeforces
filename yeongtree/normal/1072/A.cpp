#include <iostream>

using namespace std;

int main()
{
    int n,m,k; cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=(2*n+2*m-16*i-4);
    }
    cout<<ans;
    return 0;
}