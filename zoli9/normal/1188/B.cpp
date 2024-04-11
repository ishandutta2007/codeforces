#include <bits/stdc++.h>
using namespace std;
int n;
long long p, k;
map<long long, long long> ma;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p>>k;
    long long ans=0;
    for(int i=1; i<=n; i++)
    {
        long long szam, uj;
        cin>>szam;
        uj=(szam*szam)%p;
        uj=(uj*szam)%p;
        uj=(uj*szam)%p;
        long long kivon=(szam*k)%p;
        uj=(uj-kivon+p)%p;
        ans+=ma[uj];
        ma[uj]++;
    }
    cout<<ans<<endl;
    return 0;
}