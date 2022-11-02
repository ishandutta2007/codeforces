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
    int test;
    cin>>test;
    while(test--)
    {
        ll ans=0;
        int n;
        map<int, int> ma;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            x-=i;
            ans+=ma[x];
            ma[x]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}