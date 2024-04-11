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
        int n;
        cin>>n;
        vpii a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
            a[i].S=i+1;
        }
        sort(a.begin(), a.end());
        if(a[0].F==a[1].F) cout<<a[n-1].S<<'\n';
        else cout<<a[0].S<<'\n';
    }
    return 0;
}