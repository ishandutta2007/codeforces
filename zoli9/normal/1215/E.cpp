#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int bitek=20;
vi v[29];
ll srt[29][29];
ll w[21][1<<20];
ll dp[1<<20];
ll infi=1e11;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        v[szam-1].push_back(i);
    }
    for(int i=0; i<bitek; i++)
    {
        for(int j=0; j<bitek; j++)
        {
            if(i==j) continue;
            int cnt=0;
            for(int pos: v[i])
            {
                while(cnt<v[j].size() && v[j][cnt]<pos) cnt++;
                srt[i][j]+=cnt;
            }
        }
    }
    for(int msk=1; msk<(1<<bitek); msk++) dp[msk]=infi;
    dp[0]=0;
    for(int msk=1; msk<(1<<bitek); msk++)
    {
        vi bt;
        for(int i=0; i<bitek; i++)
        {
            if(msk&(1<<i)) bt.push_back(i);
        }
        for(int kezd: bt)
        {
            ll sum=0;
            for(int masik: bt)
            {
                if(kezd==masik) continue;
                sum+=srt[kezd][masik];
            }
            dp[msk]=min(dp[msk], sum+dp[msk-(1<<kezd)]);
        }

    }
    cout<<dp[(1<<bitek)-1]<<endl;


    return 0;
}