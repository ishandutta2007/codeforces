
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ans=1;
    for(int i=2; i<=n; i++)
    {
        ans+=(4*i-4);
    }
    cout<<ans<<endl;

    return 0;
}