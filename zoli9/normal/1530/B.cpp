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
        int n, m;
        cin>>n>>m;
        vector<vi> ans(n, vi(m, 0));
        for(int j=0; j<m; j++)
        {
            if(j==m-2) continue;
            if(j%2==0)
            {
                ans[0][j]=1;
                ans[n-1][j]=1;
            }
        }
        ans[0][m-1]=1;
        ans[n-1][m-1]=1;
        for(int i=0; i<n; i++)
        {
            if(i==n-2) continue;
            if(i%2==0)
            {
                ans[i][0]=1;
                ans[i][m-1]=1;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<ans[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}