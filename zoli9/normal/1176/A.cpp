#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        int ans=0;
        while(x%2==0)
        {
            x/=2;
            ans++;
        }
        while(x%3==0)
        {
            x/=3;
            ans+=2;
        }
        while(x%5==0)
        {
            x/=5;
            ans+=3;
        }
        if(x>1) cout<<-1<<endl;
        else cout<<ans<<endl;
    }


    return 0;
}