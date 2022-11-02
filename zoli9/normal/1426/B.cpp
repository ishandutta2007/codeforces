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
        int n, m;
        cin>>n>>m;
        bool ok=false;
        for(int i=1; i<=n; i++)
        {
            int a, b, c, d;
            cin>>a>>b;
            cin>>c>>d;
            if(b==c) ok=true;
        }
        if(m%2==1) ok=false;
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}