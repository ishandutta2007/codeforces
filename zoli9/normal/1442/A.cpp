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
    int n;
    while(test--)
    {
        cin>>n;
        vll a(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        ll mm=0;
        bool ok=true;
        for(int i=n-1; i>=1; i--)
        {
            a[i]-=mm;
            if(a[i]<0)
            {
                ok=false;
                break;
            }
            if(a[i]<=a[i+1]) continue;
            mm+=(a[i]-a[i+1]);
            a[i]=a[i+1];
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}