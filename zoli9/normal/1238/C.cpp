#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
vi v;
int n, h;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>h>>n;
        v.resize(n);
        for(int i=1; i<=n; i++)
        {
            cin>>v[i-1];
        }
        int ans=0;
        int cnt=1;
        int kezd=h;
        int elozo=h;
        while(1)
        {
            while(cnt<n && v[cnt]==elozo-1)
            {
                elozo=v[cnt];
                cnt++;
            }
            if((elozo-kezd+1)%2)
            {
                if(cnt==n)
                {
                    break;
                }
                else
                {
                    elozo=v[cnt]+1;
                    kezd=v[cnt]+1;
                }
            }
            else
            {
                if(elozo!=1) ans++;
                if(cnt==n) break;
                else
                {
                    elozo=v[cnt]+1;
                    kezd=v[cnt]+1;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}