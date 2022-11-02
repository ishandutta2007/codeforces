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
    int n;
    vi a;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        int ans=1;
        for(int i=1; i<n; i++)
        {
            if(a[i]!=a[i-1]) ans++;
        }
        cout<<ans<<'\n';
    }


    return 0;
}