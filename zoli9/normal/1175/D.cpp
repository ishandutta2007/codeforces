#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
vector<ll> v, w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    w.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    ll sum=0;
    for(int i=n-1; i>=0; i--)
    {
        sum+=w[i];
        if(i>0) v.push_back(sum);
    }
    ll ans=sum;
    sort(v.begin(), v.end());
    for(int i=n-2; i>n-2-(k-1); i--)
    {
        ans+=v[i];
    }
    cout<<ans<<endl;

    return 0;
}