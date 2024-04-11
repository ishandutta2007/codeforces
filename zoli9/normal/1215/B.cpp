#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n;
ll db[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    db[0]++;
    int cnt=0;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        int sz;
        cin>>sz;
        if(sz<0) cnt=1-cnt;
        db[cnt]++;
        ans+=db[1-cnt];
    }
    ll ans2=(n*(n+1))/2-ans;
    cout<<ans<<" "<<ans2<<endl;


    return 0;
}