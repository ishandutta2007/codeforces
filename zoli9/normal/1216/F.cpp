#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll dp[200009];
int prev1[200009];
string s;
int n, k;
queue<int> e1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1') e1.push(i);
        if((!e1.empty()) && e1.front()+k<i) e1.pop();
        if(e1.empty()) prev1[i]=-1;
        else prev1[i]=e1.front();
    }
    dp[0]=1;
    //cout<<prev1[11]<<endl;
    for(int i=1; i<n; i++)
    {
        dp[i]=i+1+dp[i-1];
        if(prev1[i]>=0)
        {
            int nstart=prev1[i]-k-1;
            if(nstart<0)
            {
                dp[i]=min(dp[i], (ll)(prev1[i]+1));
            }
            else
            {
                dp[i]=min(dp[i], (ll)(prev1[i]+1)+dp[nstart]);
                int pp=prev1[i]-1;
                if(pp>=0) dp[i]=min(dp[i], (ll)(prev1[i]+1)+dp[pp]);
            }
        }
        //cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}