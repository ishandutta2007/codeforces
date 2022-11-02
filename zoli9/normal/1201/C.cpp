#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> v;
int n;
ll k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll elso=1;
    ll utolso=2*1e9+5;
    int indul=n/2;
    while(elso<=utolso)
    {
        ll kozep=(elso+utolso)/2;
        ll kell=0;
        for(int i=indul; i<n; i++)
        {
            kell+=max(0ll, kozep-v[i]);
        }
        if(kell<=k) elso=kozep+1;
        else utolso=kozep-1;
    }
    cout<<utolso<<endl;
    return 0;
}