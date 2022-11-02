#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll b[200009];
ll a[200009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll maxi=0;
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        a[i]=b[i]+maxi;
        maxi=max(maxi, a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    return 0;
}