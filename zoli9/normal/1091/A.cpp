#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long y, b, r;
    cin>>y>>b>>r;
    long long ans=0;
    if(b>=y+1 && r>=y+2)
    {
        ans=max(ans, 3*y+3);
    }
    if(y>=b-1 && r>=b+1)
    {
        ans=max(ans, 3*b);
    }
    if(y>=r-2 && b>=r-1)
    {
        ans=max(ans, 3*r-3);
    }
cout<<ans<<endl;
    return 0;
}