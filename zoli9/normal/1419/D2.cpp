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
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    if(n%2==0)
    {
        for(int i=0; i+1<n/2; i++)
        {
            b[2*i+1]=a[i];
        }
        b[n-1]=a[n/2-1];
        for(int i=0; i<n/2; i++)
        {
            b[2*i]=a[i+n/2];
        }
    }
    else
    {
        for(int i=0; i<(n-1)/2; i++)
        {
            b[2*i+1]=a[i];
        }
        for(int i=0; i<(n+1)/2; i++)
        {
            b[2*i]=a[i+(n-1)/2];
        }
    }
    int ans=0;
    for(int i=1; i+1<n; i++)
    {
        if(b[i-1]>b[i] && b[i]<b[i+1]) ans++;
    }
    cout<<ans<<'\n';
    for(int x: b) cout<<x<<" ";
    cout<<'\n';
    return 0;
}