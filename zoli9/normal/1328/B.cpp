#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    ll n, m;
    while(test--)
    {
        cin>>n>>m;
        m=(n*(n-1))/2-m+1;
        ll x=n-1;
        ll e1=1;
        while(x<m)
        {
            m-=x;
            x--;
            e1++;
        }
        ll e2=e1+m;
        for(ll i=1; i<=n; i++)
        {
            if(i==e1 || i==e2) cout<<"b";
            else cout<<"a";
        }
        cout<<'\n';
    }


    return 0;
}