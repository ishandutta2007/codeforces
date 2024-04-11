#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1009];
int db[1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans=0;
    int mar=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        db[szam]++;

    }
    for(int i=1; i<=k; i++)
    {
        if(db[i]%2)
        {
            ans+=(db[i]-1);
            mar++;
        }
        else
        {
            ans+=db[i];
        }
    }
    cout<<ans+(mar+1)/2<<endl;
    return 0;
}