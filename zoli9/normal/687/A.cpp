#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[100009];
vector<int> elso, masodik;
int col[100009];
bool bejar[100009];
bool lehet;
int mely(int x)
{
    bejar[x]=true;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            col[sz]=3-col[x];
            mely(sz);
        }
        else
        {
            if(col[sz]==col[x]) lehet=false;
        }
    }
}
int main()
{
    lehet=true;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=n; i++) col[i]=-1;
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            col[i]=1;
            mely(i);
        }
    }
    if(!lehet)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(col[i]==1) elso.push_back(i);
        else masodik.push_back(i);
    }
    cout<<elso.size()<<endl;
    for(int i=0; i<elso.size(); i++) cout<<elso[i]<<" ";
    cout<<endl;
    cout<<masodik.size()<<endl;
    for(int i=0; i<masodik.size(); i++) cout<<masodik[i]<<" ";
    cout<<endl;
    return 0;
}