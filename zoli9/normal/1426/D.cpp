#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    set<ll> S;
    ll sum=0;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        if(i==1)
        {
            sum=x;
            S.insert(sum);
            continue;
        }
        sum+=x;
        if(sum==0 || S.find(sum)!=S.end())
        {
            ans++;
            S.clear();
            sum=x;
            S.insert(sum);
            continue;
        }
        S.insert(sum);
    }
    cout<<ans<<endl;
    return 0;
}