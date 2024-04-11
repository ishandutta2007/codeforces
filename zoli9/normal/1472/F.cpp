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
        ll n;
        int m;
        cin>>n>>m;
        vector<pair<ll, ll> > a(m);
        for(int i=0; i<m; i++)
        {
            cin>>a[i].S>>a[i].F;
        }
        sort(a.begin(), a.end());
        if(a.size()%2==1)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        bool ok=true;
        for(int i=0; i<m; i+=2)
        {
            if(i>0 && a[i].F==a[i-1].F)
            {
                ok=false;
                break;
            }
            if(a[i].S==a[i+1].S)
            {
                if((a[i+1].F-a[i].F)%2==0)
                {
                    ok=false;
                    break;
                }
            }
            else
            {
                if((a[i+1].F-a[i].F)%2==1)
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}