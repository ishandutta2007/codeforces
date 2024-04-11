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
        int n, x;
        cin>>n>>x;
        int ans=2;
        if(n<=2)
        {
            cout<<1<<'\n';
            continue;
        }
        n-=3;
        ans+=(n/x);
        cout<<ans<<'\n';
    }
    return 0;
}