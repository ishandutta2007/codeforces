#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int visited[100];
vector<vector<int> > grafo;

void dfs(int i)
{
    visited[i]=1;
    int vs=grafo[i].size();
    for(int j=0 ;j<vs; j++)
    {
        if(!visited[grafo[i][j]]) dfs(grafo[i][j]);
    }
    return;
}


int main()
{
    int n, m;
    cin >> n >> m;
    grafo.clear();
    grafo.resize(n);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    int can=1;
    if(n==m)
    {
        memset(visited,0,sizeof(visited));
        
        int cc=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i]){ cc++; dfs(i); }
        }
        
        if(cc>1) can=0;
    }
    else
    {
        can=0;
    }
    
    if(can)
    {
        cout << "FHTAGN!" << endl;
    }
    else
        cout << "NO" << endl;
}