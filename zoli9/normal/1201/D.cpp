#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n, m;
ll k, q;
ll mini[200009];
ll maxi[200009];
ll balra[200009];
ll jobbra[200009];
ll minsafe;
ll maxsafe;
ll dp[200009][2];
ll maxrow;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k>>q;
    mini[1]=1;
    maxi[1]=1;
    for(int i=1; i<=k; i++)
    {
        ll x, y;
        cin>>x>>y;
        maxrow=max(maxrow, x);
        maxi[x]=max(maxi[x], y);
        if(mini[x]==0 || y<mini[x]) mini[x]=y;
    }
    minsafe=200001;
    maxsafe=0;
    for(int i=0; i<q; i++)
    {
        ll sss;
        cin>>sss;
        minsafe=min(minsafe, sss);
        maxsafe=max(maxsafe, sss);
        balra[sss]=sss;
        jobbra[sss]=sss;
    }
    for(int i=1; i<=m; i++)
    {
        if(balra[i]==0)
        {
            if(i==1) balra[i]=minsafe;
            else balra[i]=balra[i-1];
        }
    }
    for(int i=m; i>=1; i--)
    {
        if(jobbra[i]==0)
        {
            if(i==m) jobbra[i]=maxsafe;
            else jobbra[i]=jobbra[i+1];
        }
    }
    dp[1][0]=2*(maxi[1]-1);
    dp[1][1]=maxi[1]-1;
    ll last=1;
    for(int i=2; i<=maxrow; i++)
    {
        if(mini[i]==0)
        {
            continue;
        }
        dp[i][0]=dp[last][0]+abs(mini[last]-balra[mini[last]])+(i-last)+abs(balra[mini[last]]-maxi[i])+abs(maxi[i]-mini[i]);
        dp[i][0]=min(dp[i][0], dp[last][0]+abs(mini[last]-jobbra[mini[last]])+(i-last)+abs(jobbra[mini[last]]-maxi[i])+abs(maxi[i]-mini[i]));
        dp[i][0]=min(dp[i][0], dp[last][1]+abs(maxi[last]-balra[maxi[last]])+(i-last)+abs(balra[maxi[last]]-maxi[i])+abs(maxi[i]-mini[i]));
        dp[i][0]=min(dp[i][0], dp[last][1]+abs(maxi[last]-jobbra[maxi[last]])+(i-last)+abs(jobbra[maxi[last]]-maxi[i])+abs(maxi[i]-mini[i]));

        dp[i][1]=dp[last][0]+abs(mini[last]-balra[mini[last]])+(i-last)+abs(balra[mini[last]]-mini[i])+abs(maxi[i]-mini[i]);
        dp[i][1]=min(dp[i][1], dp[last][0]+abs(mini[last]-jobbra[mini[last]])+(i-last)+abs(jobbra[mini[last]]-mini[i])+abs(maxi[i]-mini[i]));
        dp[i][1]=min(dp[i][1], dp[last][1]+abs(maxi[last]-balra[maxi[last]])+(i-last)+abs(balra[maxi[last]]-mini[i])+abs(maxi[i]-mini[i]));
        dp[i][1]=min(dp[i][1], dp[last][1]+abs(maxi[last]-jobbra[maxi[last]])+(i-last)+abs(jobbra[maxi[last]]-mini[i])+abs(maxi[i]-mini[i]));

        last=i;
    }
    cout<<min(dp[maxrow][0], dp[maxrow][1])<<endl;

    return 0;
}