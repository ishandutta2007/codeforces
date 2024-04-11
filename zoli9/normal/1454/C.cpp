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
        vi ans(n+1);
        vector<bool> vis(n+1, false);
        vi a(n+1);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            vis[a[i]]=true;
            if(i>1 && a[i-1]!=a[i]) ans[a[i]]++;
        }
        int answer=n;
        for(int i=1; i<=n; i++)
        {
            if(a[n]!=i) ans[i]++;
            if(vis[i]) answer=min(answer, ans[i]);
        }
        cout<<answer<<'\n';
    }
    return 0;
}