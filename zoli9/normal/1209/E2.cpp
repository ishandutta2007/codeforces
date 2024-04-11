#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int test;
int n, m;
int t[29][2009];
int maxi[2009];
int fu[29][5009];
int dp[29][5009];
vector<pii> vp;
vi masks[5009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<(1<<12); i++)
    {
        for(int j=0; j<=i; j++)
        {
            if((i|j)==i) masks[i].push_back(j);
        }
    }
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        vp.clear();
        for(int i=0; i<=12; i++)
        {
            for(int j=0; j<(1<<(12)); j++)
            {
                fu[i][j]=0;
                dp[i][j]=0;
            }
        }
        for(int i=0; i<m; i++)
        {
            maxi[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>t[i][j];
                maxi[j]=max(maxi[j], t[i][j]);
            }
        }
        for(int i=0; i<m; i++)
        {
            vp.push_back({maxi[i], i});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        for(int msk=0; msk<(1<<n); msk++)
        {
            for(int i=0; i<min(n, m); i++)
            {
                int sj=vp[i].S;
                for(int rt=0; rt<n; rt++)
                {
                    int sum=0;
                    for(int j=0; j<n; j++)
                    {
                        if(msk&(1<<j))
                        {
                            sum+=t[(j+rt)%n][sj];
                        }
                    }
                    fu[i][msk]=max(fu[i][msk], sum);
                }
            }
        }
        for(int j=0; j<(1<<n); j++) dp[0][j]=fu[0][j];
        for(int i=1; i<min(n, m); i++)
        {
            for(int m1=0; m1<(1<<n); m1++)
            {
                for(int m0: masks[m1])
                {
                    dp[i][m1]=max(dp[i][m1], fu[i][m0]+dp[i-1][m1-m0]);
                }
            }
        }
        cout<<dp[min(n, m)-1][(1<<n)-1]<<endl;
    }

    return 0;
}