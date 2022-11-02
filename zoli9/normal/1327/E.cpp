#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll p10[200009];
ll MOD=998244353;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    p10[0]=1;
    cin>>n;
    for(int i=1; i<=n+1; i++)
    {
        p10[i]=(p10[i-1]*10)%MOD;
    }
    for(int i=1; i<=n; i++)
    {
        if(i==n)
        {
            cout<<10<<" ";
            continue;
        }
        ll res=(p10[n-i-1]*18)%MOD;
        //cout<<"res: "<<res<<endl;
        if(i<n-1)
        {
            ll pl=(p10[n-i-2]*81)%MOD;
            pl=(pl*(n-i-1))%MOD;
            //cout<<"pl: "<<pl<<endl;
            res=(res+pl)%MOD;
            //cout<<i<<": "<<res<<endl;
        }
        res=(res*10)%MOD;
        cout<<res<<" ";
    }
    cout<<endl;

    return 0;
}