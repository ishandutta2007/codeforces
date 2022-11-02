#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
vi v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int ans=0;
        v.resize(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int mini=v.back();
        for(int i=(int)(v.size())-1; i>=0; i--)
        {
            if(mini<v[i]) ans++;
            mini=min(mini, v[i]);
        }
        cout<<ans<<endl;
    }


    return 0;
}