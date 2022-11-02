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

ll W[100009];

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
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>W[i];
            ans+=W[i];
        }
        vi degr(n+1, 0);
        for(int i=1; i<n; i++)
        {
            int x, y;
            cin>>x>>y;
            degr[x]++;
            degr[y]++;
        }
        vector<pair<ll, int> > Q;
        for(int i=1; i<=n; i++)
        {
            Q.push_back({W[i], degr[i]-1});
        }
        sort(Q.begin(), Q.end());
        reverse(Q.begin(), Q.end());
        cout<<ans;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=Q[i].S; j++)
            {
                ans+=Q[i].F;
                cout<<" "<<ans;
            }
        }
        cout<<'\n';
    }
    return 0;
}