#include <bits/stdc++.h>
using namespace std;
vector<long long> key, people;
long long n, k, p;
long long dp[1009][2009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k>>p;
    for(int i=1; i<=n; i++)
    {
        long long szam;
        cin>>szam;
        people.push_back(szam);
    }
    for(int i=1; i<=k; i++)
    {
        long long szam;
        cin>>szam;
        key.push_back(szam);
    }
    sort(people.begin(), people.end());
    sort(key.begin(), key.end());
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i>j)
            {
                dp[i][j]=-1;
                continue;
            }
            dp[i][j]=max(abs(people[i-1]-key[j-1])+abs(key[j-1]-p), dp[i-1][j-1]);
            if(i<j)
            {
                dp[i][j]=min(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}