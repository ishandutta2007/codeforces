#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    bool lgt[n]; for(int i=0;i<n;i++) cin>>lgt[i];
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        if((!lgt[i])&&lgt[i-1]&&lgt[i+1])
        {
            lgt[i+1]=false; ans++;
        }
    }
    cout<<ans;
    return 0;
}