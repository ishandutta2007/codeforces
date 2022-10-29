#include <bits/stdc++.h>
using namespace std;

int deg[100006];

vector<int> G[100006];

int root;

void dfs(int now,int par)
{
    bool gett=false;
    for (int i:G[now])
    {
        if (i==par)continue;
        gett=true;
        dfs(i,now);
    }
    if(!gett)
    {
        cout<<root<<' '<<now<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    if (n==2)
    {
        cout<<"Yes"<<endl;
        cout<<"1"<<endl;
        cout<<"1 2"<<endl;
        return 0;
    }
    for(int i=0;n-1>i;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    root = -1;
    for (int i=1;n>=i;i++)
    {
        if (deg[i]>2)
        {
            if(root!=-1)
            {
                cout<<"No"<<endl;
                return 0;
            }
            root = i;
        }
    }
    if (root == -1) root = 1;
    cout << "Yes"<<endl;
    cout<<deg[root]<<endl;
    for (int i:G[root])
    {
        dfs(i,root);
    }
}