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
        int n, m;
        cin>>n;
        vi a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        cin>>m;
        vi b(m);
        for(int i=0; i<m; i++) cin>>b[i];
        int ans=0;
        int mini=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
            ans=max(ans, sum-mini);
            //mini=min(sum, mini);
        }
        int ans2=0;
        int mini2=0;
        int sum2=0;
        for(int i=0; i<m; i++)
        {
            sum2+=b[i];
            ans2=max(ans2, sum2-mini2);
            //mini2=min(sum2, mini2);
        }
        cout<<ans+ans2<<'\n';
    }
    return 0;
}