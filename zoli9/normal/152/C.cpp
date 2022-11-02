#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[109];
bool abc[109][26];
long long MOD=1000000007;
long long ans=1;
long long hany[109];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        for(int j=0; j<s[i].size(); j++)
        {
            abc[j][s[i][j]-'A']=true;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(abc[i][j])
            {
                hany[i]++;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        ans*=hany[i];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}