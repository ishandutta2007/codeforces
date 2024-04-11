#include <bits/stdc++.h>
using namespace std;
string s[3];
long long n;
long long darabsm[3][26];
long long darablg[3][26];
long long maxi[3];
long long mm[3];
string nev[3];
vector<pair<long long, string> > v;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    nev[0]="Kuro";
    nev[1]="Shiro";
    nev[2]="Katie";
    for(int u=0; u<3; u++)
    {
        long long hh=(long long)(s[u].size());
        for(int i=0; i<s[u].size(); i++)
        {
            if('a'<=s[u][i] && s[u][i]<='z')
            {
                darabsm[u][s[u][i]-'a']++;
            }
            else
            {
                darablg[u][s[u][i]-'A']++;
            }
        }
        maxi[u]=0;
        for(int i=0; i<26; i++)
        {
            maxi[u]=max(maxi[u], darabsm[u][i]);
            maxi[u]=max(maxi[u], darablg[u][i]);
        }
        mm[u]=min(hh, n+maxi[u]);
        if(n==1 && maxi[u]==hh && hh!=1) mm[u]--;
        v.push_back({mm[u], nev[u]});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if(v[0].first==v[1].first)
    {
        cout<<"Draw"<<endl;
        return 0;
    }
    cout<<v[0].second<<endl;
    return 0;
}