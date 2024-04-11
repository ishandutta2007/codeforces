#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<ll, pii>> elek;
int n, m, k;
map<int, int> idx;
vector<ll> ans;
ll dist[809][809];
ll infi=1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    elek.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>elek[i].S.F>>elek[i].S.S>>elek[i].F;
    }
    sort(elek.begin(), elek.end());
    int kell=min(k, m);
    int dbcsucs=0;
    for(int i=0; i<kell; i++)
    {
        int v1=elek[i].S.F;
        int v2=elek[i].S.S;
        if(idx[v1]<=0)
        {
            dbcsucs++;
            idx[v1]=dbcsucs;
        }
        if(idx[v2]<=0)
        {
            dbcsucs++;
            idx[v2]=dbcsucs;
        }
        //cout<<v1<<" es "<<v2<<endl;
    }
    for(int i=1; i<=dbcsucs; i++)
    {
        for(int j=1; j<=dbcsucs; j++)
        {
            dist[i][j]=infi;
        }
        dist[i][i]=0;
    }
    for(int i=0; i<kell; i++)
    {
        int v1=idx[elek[i].S.F];
        int v2=idx[elek[i].S.S];
        dist[v1][v2]=elek[i].F;
        dist[v2][v1]=elek[i].F;
    }

    /*for(int i=1; i<=dbcsucs; i++)
    {
        for(int j=1; j<=dbcsucs; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int k=1; k<=dbcsucs; k++)
    {
        for(int i=1; i<=dbcsucs; i++)
        {
            for(int j=1; j<=dbcsucs; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=1; i<=dbcsucs; i++)
    {
        for(int j=i+1; j<=dbcsucs; j++)
        {
            ans.push_back(dist[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans[k-1]<<endl;

    return 0;
}