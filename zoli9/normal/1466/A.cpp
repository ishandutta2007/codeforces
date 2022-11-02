#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vi a(n);
        vector<bool> was(1009, false);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(!was[a[j]-a[i]])
                {
                    was[a[j]-a[i]]=true;
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}