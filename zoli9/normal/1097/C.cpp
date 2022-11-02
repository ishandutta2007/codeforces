#include <bits/stdc++.h>
using namespace std;
vector<string> s;
int semleges;
int kk[500009];
int vv[500009];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    s.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        int nyit=0;
        int csuk=0;
        int elso=0;
        int utolso=0;
        bool kezdo=true;
        bool vegso=true;
        for(int j=0; j<s[i].size(); j++)
        {
            if(s[i][j]=='(')
            {
                elso++;
                nyit++;
            }
            else
            {
                elso--;
                if(elso<0) kezdo=false;
                csuk++;
            }
        }
        for(int j=s[i].size()-1; j>=0; j--)
        {
            if(s[i][j]=='(')
            {
                utolso--;
                if(utolso<0) vegso=false;
            }
            else
            {
                utolso++;
            }
        }
        if(kezdo && vegso)
        {
            semleges++;
        }
        else if(kezdo)
        {
            kk[nyit-csuk]++;
        }
        else if(vegso)
        {
            vv[csuk-nyit]++;
        }
    }
    int ans=0;
    for(int i=500000; i>=1; i--)
    {
        ans+=(min(kk[i], vv[i]));
    }
    int mini=min(kk[0], vv[0]);
    int maxi=max(kk[0], vv[0]);
    ans+=mini;
    int marad=maxi-mini;
    if(semleges>=marad)
    {
        ans+=((semleges+marad)/2);
    }
    else
    {
        ans+=semleges;
    }
    cout<<ans<<endl;
    return 0;
}