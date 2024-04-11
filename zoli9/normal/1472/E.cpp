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

int infi=1e9+9;

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
        vector<pair<pii, int> > a(n);
        for(int i=0; i<n; i++)
        {
            int x, y;
            cin>>x>>y;
            if(x>y) swap(x, y);
            a[i].F.F=x;
            a[i].F.S=y;
            a[i].S=i+1;
        }
        sort(a.begin(), a.end());
        int cnt=0;
        int mini=infi;
        int idx=-1;
        while(cnt<n)
        {
            vector<pair<pii, int> > cur;
            cur.push_back(a[cnt]);
            cnt++;
            while(cnt<n && a[cnt].F.F==cur.back().F.F)
            {
                cur.push_back(a[cnt]);
                cnt++;
            }
            for(int i=0; i<cur.size(); i++)
            {
                if(mini<cur[i].F.S)
                {
                    ans[cur[i].S]=idx;
                }
                else
                {
                    ans[cur[i].S]=-1;
                }
            }
            for(int i=0; i<cur.size(); i++)
            {
                if(cur[i].F.S<mini)
                {
                    mini=cur[i].F.S;
                    idx=cur[i].S;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}