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
    ll n, k;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        if((k*k)%2 != n%2)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        if((k*k)>n)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<'\n';
    }


    return 0;
}