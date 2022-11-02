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
        int n;
        cin>>n;
        map<int, int> cnt;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        int maxi=0;
        for(auto it=cnt.begin(); it!=cnt.end(); it++)
        {
            maxi=max(maxi, it->second);
        }
        int ans=0;
        if(n%2==1) ans=1;
        int ot=n-maxi;
        ans=max(ans, n-2*ot);
        cout<<ans<<'\n';
    }
    return 0;
}