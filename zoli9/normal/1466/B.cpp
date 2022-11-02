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
        int ans=0;
        vector<bool> was(2*n+2, false);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(was[a[i]])
            {
                if(!was[a[i]+1])
                {
                    was[a[i]+1]=true;
                    ans++;
                }
            }
            else
            {
                ans++;
                was[a[i]]=true;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}