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

ll dp[300009][2];

ll ans=0;
int n;
vll a;

void bb(int x)
{
    if(x<=0 || x>n) return;
    if(a[x]>a[x-1] && a[x]>a[x+1]) ans-=a[x];
    if(a[x]<a[x-1] && a[x]<a[x+1]) ans+=a[x];
}
void ff(int x)
{
    if(x<=0 || x>n) return;
    if(a[x]>a[x-1] && a[x]>a[x+1]) ans+=a[x];
    if(a[x]<a[x-1] && a[x]<a[x+1]) ans-=a[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ans=0;
        int q;
        cin>>n>>q;
        a.assign(n+2, 0);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1]) ans+=a[i];
            if(a[i]<a[i-1] && a[i]<a[i+1]) ans-=a[i];
        }
        cout<<ans<<'\n';
        for(int u=1; u<=q; u++)
        {
            int le, ri;
            cin>>le>>ri;
            vi w;
            w.push_back(le-1);
            w.push_back(le);
            w.push_back(le+1);
            w.push_back(ri-1);
            w.push_back(ri);
            w.push_back(ri+1);
            sort(w.begin(), w.end());
            for(int i=0; i<w.size(); i++)
            {
                if(i==0 || w[i]!=w[i-1]) bb(w[i]);
            }
            swap(a[le], a[ri]);
            for(int i=0; i<w.size(); i++)
            {
                if(i==0 || w[i]!=w[i-1]) ff(w[i]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}