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

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        int n=s.size();
        vi dp(n+2, 0);
        if(n>0 && s[n-1]==s[n-2]) dp[n-2]=1;
        for(int i=n-3; i>=0; i--)
        {
            if(s[i]==s[i+1])
            {
                if(s[i]==s[i+2])
                {
                    dp[i]=dp[i+3]+2;
                }
                else
                {
                    dp[i]=dp[i+2]+1;
                }
            }
            else if(s[i]==s[i+2])
            {
                if(i+3<n && s[i+1]==s[i+3])
                {
                    dp[i]=dp[i+4]+2;
                }
                else
                {
                    dp[i]=dp[i+3]+1;
                }
            }
            else
            {
                dp[i]=dp[i+1];
            }
        }
        cout<<dp[0]<<'\n';
    }
    return 0;
}