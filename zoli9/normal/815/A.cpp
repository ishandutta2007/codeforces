#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
int t[109][109];
int dbsor[109][509];
int dbosz[109][509];
vector<pair<string, int> > ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>t[i][j];
        }
    }
    int s1min=t[1][1];
    for(int j=2; j<=m; j++)
    {
        s1min=min(s1min, t[1][j]);
    }
    for(int j=1; j<=m; j++)
    {
        if(t[1][j]>s1min)
        {
            int dif=t[1][j]-s1min;
            for(int u=1; u<=dif; u++)
            {
                ans.push_back({"col", j});
            }
            for(int i=1; i<=n; i++)
            {
                t[i][j]-=dif;
                if(t[i][j]<0)
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    int omin=t[1][1];
    for(int i=1; i<=n; i++)
    {
        omin=min(omin, t[i][1]);
        for(int j=2; j<=m; j++)
        {
            if(t[i][j]!=t[i][j-1])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(t[i][1]>omin)
        {
            int dif=t[i][1]-omin;
            for(int u=1; u<=dif; u++)
            {
                ans.push_back({"row", i});
            }
            for(int j=1; j<=m; j++)
            {
                t[i][j]-=dif;
                if(t[i][j]<0)
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    if(t[1][1]>0)
    {
        if(n<=m)
        {
            for(int i=1; i<=n; i++)
            {
                for(int u=1; u<=t[1][1]; u++)
                {
                    ans.push_back({"row", i});
                }
            }
        }
        else
        {
            for(int j=1; j<=m; j++)
            {
                for(int u=1; u<=t[1][1]; u++)
                {
                    ans.push_back({"col", j});
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].F<<" "<<ans[i].S<<endl;
    }
    return 0;
}