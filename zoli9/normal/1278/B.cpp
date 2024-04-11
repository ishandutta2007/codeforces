#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    ll a, b;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        if(a>b) swap(a, b);
        ll sum=0;
        ll i=1;
        bool talalt=false;
        while(!talalt)
        {
            sum+=i;
            if(a+sum>=b && (a+sum+b)%2==0)
            {
                cout<<i<<endl;
                talalt=true;
            }
            i++;
        }
    }

    return 0;
}