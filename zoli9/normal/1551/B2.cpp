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
        int n, k;
        cin>>n>>k;
        vpii a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
            a[i].S=i;
        }
        sort(a.begin(), a.end());
        vector<vpii> pr(k, vpii());
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(pr[c].size()==0 || pr[c].back().F!=a[i].F)
            {
                pr[c].push_back(a[i]);
                c=(c+1)%k;
            }
        }
        vi ans(n, 0);
        int maxsize=pr[0].size();
        for(int i=0; i<k; i++) maxsize=min(maxsize, (int)pr[i].size());
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<maxsize; j++)
            {
                ans[pr[i][j].S]=i+1;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}