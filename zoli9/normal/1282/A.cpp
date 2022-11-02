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
    ll a, b, c, r;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>a>>b>>c>>r;
        ll d=c-r;
        ll e=c+r;
        if(a>b) swap(a, b);
        if(d<a)
        {
            if(e>b)
            {
                cout<<0<<endl;
                continue;
            }
            if(e<a)
            {
                cout<<b-a<<endl;
                continue;
            }
            cout<<b-e<<endl;
            continue;
        }
        if(e<b)
        {
            cout<<(b-a)-(e-d)<<endl;
            continue;
        }
        if(d>b)
        {
            cout<<b-a<<endl;
            continue;
        }
        cout<<d-a<<endl;
    }


    return 0;
}