#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graf[505];
int in[505], cop[505];
bool don[505];
int n, m, f;
queue<int> q;

int del(int v)
{
    int d = 0;
    q.push(v);
    //cout<<v<<endl;
    while(!q.empty())
    {
        int u = q.front();
        //cout<<"!"<<u<<endl;
        q.pop();
        don[u] = true;
        d++;
        for(int i = 0; i < graf[u].size(); i++)
        {
            in[graf[u][i]]--;
            if(in[graf[u][i]] == 0 && graf[u][i] != v)
                q.push(graf[u][i]);
        }
    }
    //cout<<"$"<<d<<endl;
    return d;
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        in[b]++;
        graf[a].push_back(b);
    }
    int x;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0 && !don[i])
            x = del(i);
    //cout<<"?"<<x<<endl;
    for(int i = 1; i <= n; i++)
        if(in[i] != 0)
            f++;
    //cout<<f<<endl;
    if(f == 0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cop[j] = in[j];
        if(in[i] == 1 && del(i) == f)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        for(int j = 1; j <= n; j++)
            in[j] = cop[j];
    }
    cout<<"NO"<<endl;
    return 0;
}