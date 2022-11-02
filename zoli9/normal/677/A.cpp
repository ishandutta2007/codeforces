#include <bits/stdc++.h>
using namespace std;
int n, h, ans;
int t[1009];
int main()
{
    cin>>n>>h;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(t[i]>h) ans+=2;
        else ans++;
    }
    cout<<ans;
    return 0;
}