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

ll n;
ll x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>x;
        ll sum=0;
        bool same=true;
        bool wsame=false;
        for(int i=1; i<=n; i++)
        {
            ll y;
            cin>>y;
            if(y!=x) same=false;
            if(y==x) wsame=true;
            sum+=y;
        }
        if(same)
        {
            cout<<0<<'\n';
            continue;
        }
        if(x*n==sum || wsame)
        {
            cout<<1<<'\n';
            continue;
        }
        cout<<2<<'\n';
    }
    return 0;
}