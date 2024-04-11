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

ll MOD=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    int n, k;
    while(test--)
    {
        cin>>n>>k;
        vi a(n+1);
        vi hol(n+1);
        vi b(k+1);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            hol[a[i]]=i;
        }
        for(int i=1; i<=k; i++)
        {
            cin>>b[i];
            b[i]=hol[b[i]];
        }
        vector<bool> was(n+1, false);
        ll ans=1;
        for(int i=k; i>=1; i--)
        {
            ll mt=0;
            if(b[i]<n)
            {
                if(!was[b[i]+1])
                {
                    mt++;
                }
            }
            if(b[i]>1)
            {
                if(!was[b[i]-1])
                {
                    mt++;
                }
            }
            if(mt==0)
            {
                ans=0;
                break;
            }
            ans=(ans*mt)%MOD;
            was[b[i]]=true;
        }
        cout<<ans<<'\n';
    }
    return 0;
}