#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
string z;
int eddigdb[26];
int meddig[26][200009];
int db[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        meddig[s[i]-'a'][eddigdb[s[i]-'a']+1]=i+1;
        eddigdb[s[i]-'a']++;
    }
    cin>>m;
    for(int j=1; j<=m; j++)
    {
        cin>>z;
        for(int i=0; i<26; i++) db[i]=0;
        for(int i=0; i<z.size(); i++)
        {
            db[z[i]-'a']++;
        }
        int ans=0;
        for(int i=0; i<26; i++)
        {
            ans=max(ans, meddig[i][db[i]]);
        }
        cout<<ans<<endl;
    }


    return 0;
}