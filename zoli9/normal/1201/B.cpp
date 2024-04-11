#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll sum=0;
    ll maxi=0;
    for(int i=1; i<=n; i++)
    {
        ll szam;
        cin>>szam;
        maxi=max(maxi, szam);
        sum+=szam;
    }
    if(sum%2==0 && sum-maxi>=maxi) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}