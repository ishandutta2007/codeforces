#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int dp[109][109][109]; // honnan, hossz, kezd
int sum[109][109];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>s;
    int h=n;
    for(int i=h; i>=0; i--)
    {
        sum[i][0]=1;
    }
    for(int i=h-1; i>=0; i--)
    {
        for(int hossz=1; hossz<=h; hossz++)
        {
            for(int kezd=0; kezd<26; kezd++)
            {
                if(s[i]-'a'==kezd)
                {
                    dp[i][hossz][kezd]=sum[i+1][hossz-1];
                }
                else
                {
                    dp[i][hossz][kezd]=dp[i+1][hossz][kezd];
                }
                sum[i][hossz]+=dp[i][hossz][kezd];
            }
            sum[i][hossz]=min(sum[i][hossz], 10000);
        }
    }
    long long ans=0;
    for(int i=n; i>=0; i--)
    {
        if(k>sum[0][i])
        {
            ans+=(((long long)(n-i))*sum[0][i]);
            k-=sum[0][i];
        }
        else
        {
            ans+=(((long long)(n-i))*k);
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}