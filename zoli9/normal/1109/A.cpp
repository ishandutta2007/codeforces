#include <bits/stdc++.h>
using namespace std;
long long n;
long long xo;
long long odd[1100009];
long long even[1100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    even[0]++;
    for(int i=1; i<=n; i++)
    {
        long long sza;
        cin>>sza;
        xo = xo ^ sza;
        if(i%2==1)
        {
            odd[xo]++;
        }
        else
        {
            even[xo]++;
        }
    }
    long long ans=0;
    for(int i=0; i<=1100000; i++)
    {
        long long mo = (odd[i]*(odd[i]-1))/2;
        long long me = (even[i]*(even[i]-1))/2;
        ans+=mo;
        ans+=me;
    }
    cout<<ans<<endl;
    return 0;
}