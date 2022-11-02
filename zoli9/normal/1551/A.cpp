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
        ll a;
        cin>>a;
        ll x=a/3;
        if(a%3==0)
        {
            cout<<x<<" "<<x<<'\n';
        }
        else if(a%3==1)
        {
            cout<<x+1<<" "<<x<<'\n';
        }
        else
        {
            cout<<x<<" "<<x+1<<'\n';
        }
    }
    return 0;
}