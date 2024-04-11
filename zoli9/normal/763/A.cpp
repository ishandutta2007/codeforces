#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[100009];
int color[100009];
int e1=0, e2=0;
bool jo1=true;
bool jo2=true;
int besz[100009];
void dfs1(int x)
{
    besz[x]=1;
    for(int sz: G[x])
    {
        if(besz[sz]!=1)
        {
            if(color[sz]!=color[x])
            {
                jo1=false;
            }
            else
            {
                dfs1(sz);
            }
        }
    }
}
void dfs2(int x)
{
    besz[x]=2;
    for(int sz: G[x])
    {
        if(besz[sz]!=2)
        {
            if(color[sz]!=color[x])
            {
                jo2=false;
            }
            else
            {
                dfs2(sz);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>color[i];
    }
    bool vanrossz=false;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
            int szom=G[i][j];
            if(color[i]!=color[szom])
            {
                e1=i;
                e2=szom;
                vanrossz=true;
                break;
            }
        }
        if(vanrossz) break;
    }
    if(e1==0)
    {
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return 0;
    }
    besz[e1]=1;
    for(int i=0; i<G[e1].size(); i++)
    {
        dfs1(G[e1][i]);
    }
    if(jo1)
    {
        cout<<"YES"<<endl;
        cout<<e1<<endl;
        return 0;
    }
    besz[e2]=2;
    for(int i=0; i<G[e2].size(); i++)
    {
        dfs2(G[e2][i]);
    }
    if(jo2)
    {
        cout<<"YES"<<endl;
        cout<<e2<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}