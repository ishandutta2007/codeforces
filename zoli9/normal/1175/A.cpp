#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
ll n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        ll ans=n%k;
        n=n-n%k;
        while(n>0)
        {
            ans++;
            n/=k;
            ans+=(n%k);
            n=n-n%k;
        }
        cout<<ans<<endl;
    }


    return 0;
}