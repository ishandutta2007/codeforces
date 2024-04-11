#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int v[1000009];
int mini[1000009];
int addigmin[1000009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    v[0]=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i-1]=='(') v[i]=v[i-1]+1;
        else v[i]=v[i-1]-1;
        addigmin[i]=min(addigmin[i-1], v[i]);
    }
    int ans=0;
    int mini=v[n];
    for(int i=n; i>=1; i--)
    {
        mini=min(mini, v[i]);
        if(addigmin[i-1]<0) continue;
        if(s[i-1]=='(')
        {
            if(mini>=2 && v[n]==2) ans++;
        }
        else
        {
            if(mini>=-2 && v[n]==-2) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}