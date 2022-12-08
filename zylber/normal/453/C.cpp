#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int> > grafo;
vector<int> ans;
vector<int> curans;
int visited[100010];
int parity[100010];

void visit(int i)
{
    parity[i]=(parity[i]+1)%2;
    curans.push_back(i);
}

void dfs(int i, int p)
{
    visit(i);
    visited[i]=1;
    
    int vs=grafo[i].size();
    
    for(int j=0; j<vs; j++)
    {
        if(!visited[grafo[i][j]])
        {
            dfs(grafo[i][j], i);
            visit(i);
        }
    }
    
    if(parity[i] && p!=-1)
    {
        visit(p);
        visit(i);
    }
    if(parity[i] && p==-1)
    {
        curans.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    grafo.resize(n);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    
    memset(visited,0,sizeof(visited));
    
    for(int i=0; i<n; i++)
    {
        cin >> parity[i];
    }
    
    int odd=0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && parity[i])
        {
            odd++;
            curans.clear();
            dfs(i, -1);
        }
    }
    
    if(odd<=1)
    {
        int cs=curans.size();
        cout << cs << endl;
        for(int i=0; i<cs; i++)
        {
            if(i) cout << " ";
            cout << curans[i]+1;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}