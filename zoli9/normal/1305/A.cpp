#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    int n;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        a.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<'\n';
        for(int i=0; i<n; i++) cout<<b[i]<<" ";
        cout<<'\n';
    }



    return 0;
}