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
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    if(n%2==0)
    {
        cout<<(n-2)/2<<'\n';
    }
    else
    {
        cout<<(n-1)/2<<'\n';
    }
    int k=0;
    int v=n-1;
    for(int i=0; i<n; i++)
    {
        if(i%2==0) cout<<a[v--]<<" ";
        else cout<<a[k++]<<" ";
    }
    cout<<'\n';
    return 0;
}