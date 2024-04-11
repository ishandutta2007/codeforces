#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i=0;n>i;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x]=max(mp[x],y);
    }
    cin>>n;
    for(int i=0;n>i;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x]=max(mp[x],y);
    }
    long long ans=0;
    for(pair<int,int> p:mp)
    {
        ans+=p.second;
    }
    cout<<ans<<endl;
}