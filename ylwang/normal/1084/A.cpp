#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[102];
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i]*(i-1)*4;
    }
    cout<<ans;
    return 0;
}