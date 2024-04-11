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
    ll x, y;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>x>>y;
        if(x==y+1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }


    return 0;
}