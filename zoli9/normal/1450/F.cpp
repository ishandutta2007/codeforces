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
        vi a(n+1);
        vi db(n+1, 0);
        vi d2(n+1, 0);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            db[a[i]]++;
        }
        int maxi=0;
        for(int i=1; i<=n; i++)
        {
            maxi=max(maxi, db[i]);
        }
        if(maxi>n-maxi+1)
        {
            cout<<-1<<'\n';
            continue;
        }
        d2[a[1]]++;
        int y=0;
        for(int i=2; i<=n; i++)
        {
            if(a[i]==a[i-1])
            {
                d2[a[i]]+=2;
                y++;
            }
        }
        d2[a[n]]++;
        int maxi2=0;
        for(int i=1; i<=n; i++)
        {
            maxi2=max(maxi2, d2[i]);
        }
        int ans=y+max(0, maxi2-y-2);
        cout<<ans<<'\n';
    }
    return 0;
}