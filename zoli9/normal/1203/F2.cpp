#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> pos;
vector<pii> neg;
int n, r;
int dp[109][60009];
bool rendez(pii x, pii y)
{
    return x.F+x.S>y.F+y.S;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r;
    for(int i=0; i<n; i++)
    {
        pii cur;
        cin>>cur.F>>cur.S;
        if(cur.S>=0) pos.push_back(cur);
        else neg.push_back(cur);
    }
    sort(pos.begin(), pos.end());
    int ans=0;
    for(int i=0; i<pos.size(); i++)
    {
        if(pos[i].F<=r)
        {
            r+=pos[i].S;
            ans++;
        }
    }
    sort(neg.begin(), neg.end(), rendez);
    int nn=neg.size();
    if(nn==0)
    {
        cout<<ans<<endl;
        return 0;
    }
    for(int j=0; j<=r; j++)
    {
        if(neg[nn-1].F<=j && j+neg[nn-1].S>=0) dp[nn-1][j]=1;
        else dp[nn-1][j]=0;
    }
    for(int i=nn-2; i>=0; i--)
    {
        for(int j=0; j<=r; j++)
        {
            dp[i][j]=dp[i+1][j];
            if(neg[i].F<=j && j+neg[i].S>=0)
            {
                dp[i][j]=max(dp[i][j], dp[i+1][j+neg[i].S]+1);
            }
        }
    }
    cout<<ans+dp[0][r]<<endl;
    return 0;
}