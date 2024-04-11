#include <bits/stdc++.h>
using namespace std;
int n, s;
int ans;
int main()
{
    cin>>n>>s;
    ans=s;
    for(int i=1; i<=n; i++)
    {
        int a, b;
        cin>>a>>b;
        ans=max(ans, a+b);
    }
    cout<<ans;
    return 0;
}