#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int n, d;
int t[109];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>t[i];
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            while(t[i]>0 && d>=i-1)
            {
                ans+=1;
                d-=(i-1);
                t[i]--;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}