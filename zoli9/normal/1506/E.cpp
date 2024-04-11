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
        vector<bool> was(n+1, false);
        vi ans(n+1, -1);
        vi a(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(i==1 || a[i]!=a[i-1])
            {
                was[a[i]]=true;
                ans[i]=a[i];
            }
        }
        set<int> unused;
        for(int i=1; i<=n; i++)
        {
            if(!was[i]) unused.insert(i);
        }
        auto it=unused.begin();
        for(int i=1; i<=n; i++)
        {
            if(ans[i]>=0) cout<<ans[i]<<" ";
            else
            {
                cout<<(*it)<<" ";
                it++;
            }
        }
        cout<<'\n';
        int border=0;
        for(int i=1; i<=n; i++)
        {
            if(ans[i]>=0)
            {
                cout<<ans[i]<<" ";
                border=ans[i];
            }
            else
            {
                it=unused.lower_bound(border);
                it--;
                int x=(*it);
                cout<<x<<" ";
                unused.erase(x);
            }
        }
        cout<<'\n';
    }
    return 0;
}