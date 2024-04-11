#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PI 3.14159265358979323846

vi x[100007];
bool h[100007];
vi no;

bool bs(int i, int s, int kezd, int veg)
{
    if(veg<=kezd+1)
    {
        if(x[i][veg]==s || x[i][kezd]==s)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int mid=(kezd+veg)/2;
    if (x[i][mid]>s) return bs(i,s,kezd,mid-1);
    if (x[i][mid]<s) return bs(i,s,mid+1,veg);
    if (x[i][mid]==s)  return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0) no.pb(i);
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        int y=(u-v+n)%n;
        if(y>n/2) y=n-y;
        if(n%2==0 && y==n/2)
        {
            x[y].pb(u);
            x[y].pb(v);
            continue;
        }
        if((u+y)%n==v%n) x[y].pb(u);
        else x[y].pb(v);
    }
    for(int i=1;i<=n/2;i++)
    {
        sort(x[i].begin(),x[i].end());
        for(int j=0;j<no.size();j++)
        {
            for(int k=0;k<x[i].size();k++)
            {
                int y=(x[i][k]+no[j])%n;
                if(y==0) y=n;
                if (!bs(i,y,0,x[i].size()-1))
                {
                    h[j]=true;
                }
            }
        }
    }
    for(int i=0;i<no.size();i++)
    {
        if(!h[i])
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}