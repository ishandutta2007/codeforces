#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
string s;
int db[20][20];
int dbmask[20][1200009];
int dp[1200009];
int infi=100000009;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1]) continue;
        db[s[i]-'a'][s[i-1]-'a']++;
        db[s[i-1]-'a'][s[i]-'a']++;
    }
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<m; i++)
        {
            for(int mask=(1<<i); mask<(1<<(i+1)); mask++)
            {
                dbmask[j][mask]=dbmask[j][mask-(1<<i)]+db[j][i];
            }
        }
    }
    dp[0]=0;
    for(int mask=1; mask<(1<<m); mask++)
    {
        dp[mask]=infi;
        vi kell;
        for(int i=0; i<m; i++)
        {
            if((mask|(1<<i))==mask)
            {
                kell.push_back(i);
            }
        }
        int h=kell.size();
        for(int i: kell)
        {
            dp[mask]=min(dp[mask], dp[mask-(1<<i)]+(h-1)*(dbmask[i][mask-(1<<i)]-dbmask[i][(1<<m)-1-mask]));
        }
        //cout<<mask<<" "<<dp[mask]<<endl;
    }
    cout<<dp[(1<<m)-1]<<endl;

    return 0;
}