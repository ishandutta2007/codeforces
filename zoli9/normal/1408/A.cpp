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
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        vi a(n);
        vi b(n);
        vi c(n);
        vi ans(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
        }
        ans[0]=a[0];
        for(int i=1; i+1<n; i++)
        {
            if(a[i]!=ans[i-1])
            {
                ans[i]=a[i];
                continue;
            }
            if(b[i]!=ans[i-1])
            {
                ans[i]=b[i];
                continue;
            }
            if(c[i]!=ans[i-1])
            {
                ans[i]=c[i];
                continue;
            }
        }
        if(a[n-1]!=ans[n-2] && a[n-1]!=ans[0]) ans[n-1]=a[n-1];
        else if(b[n-1]!=ans[n-2] && b[n-1]!=ans[0]) ans[n-1]=b[n-1];
        else ans[n-1]=c[n-1];
        for(int x: ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}