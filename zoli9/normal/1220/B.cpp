#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
ll t[1009][1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>t[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int j1, j2;
        if(i>=3)
        {
            j1=1;
            j2=2;
        }
        else if(i==2)
        {
            j1=1;
            j2=3;
        }
        else
        {
            j1=2;
            j2=3;
        }
        ll ans=t[i][j1]*t[i][j2];
        ans/=t[j1][j2];
        ans=sqrt(ans);
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}