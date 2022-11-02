#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> parok[200009];
vector<int> G[200009];
int szin[200009];
void dfs(int x)
{
    for(int sz: G[x])
    {
        if(szin[sz]==0)
        {
            szin[sz]=3-szin[x];
            dfs(sz);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>parok[i].first>>parok[i].second;
        G[parok[i].first].push_back(parok[i].second);
        G[parok[i].second].push_back(parok[i].first);
    }
    for(int i=1; i<=2*n; i++)
    {
        if(i%2) G[i].push_back(i+1);
        else G[i].push_back(i-1);
    }
    for(int i=1; i<=2*n; i++)
    {
        if(szin[i]==0)
        {
            szin[i]=1;
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<szin[parok[i].first]<<" "<<szin[parok[i].second]<<endl;
    }
    return 0;
}