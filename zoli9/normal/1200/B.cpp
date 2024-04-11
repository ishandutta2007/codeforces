#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
ll n, m, k;
ll h[109];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>h[i];
        }
        bool jo=true;
        m+=h[1];
        for(int i=2; i<=n; i++)
        {
            if(m+k<h[i])
            {
                jo=false;
                break;
            }
            ll marad=max(0ll, h[i]-k);
            m-=marad;
            m+=h[i];
        }

            if(jo) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

    }


    return 0;
}