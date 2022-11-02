#include <bits/stdc++.h>
using namespace std;
long long n, k, h;
long long t[100009];
int main()
{
    cin>>n>>h>>k;
    for(int i=1; i<=n; i++) cin>>t[i];
    long long akt=0, ans=0;
    for(int i=1; i<=n; i++)
    {
        akt+=t[i];
        ans+=(akt/k);
        akt%=k;
        if(i==n)
        {
            if(akt>0) ans++;
        }
        else
        {
            if(t[i+1]+akt>h)
            {
                ans++;
                akt=0;
            }
        }
    }
    cout<<ans;
    return 0;
}