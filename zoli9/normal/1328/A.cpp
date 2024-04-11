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
    while(test--)
    {
        ll a, b;
        cin>>a>>b;
        ll m=a%b;
        if(m==0) cout<<0<<'\n';
        else cout<<(b-m)<<'\n';
    }


    return 0;
}