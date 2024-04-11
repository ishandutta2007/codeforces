#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int n;
int m;
vector<int> G[300009];
vector<int> edgenum[300009];
bool bejar[300009];
vector<int> ans;
vector<int> is;
void dfs(int x, int good)
{
    bejar[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        int sz=G[x][i];
        if(!bejar[sz])
        {
            if(good>0)
            {
                ans.push_back(edgenum[x][i]);
            }
            return dfs(sz, 1-good);
        }
    }
    is.push_back(x);
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        ans.clear();
        is.clear();
        for(int i=1; i<=3*n; i++)
        {
            G[i].clear();
            edgenum[i].clear();
            bejar[i]=false;
        }
        for(int i=1; i<=m; i++)
        {
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
            edgenum[a].push_back(i);
            edgenum[b].push_back(i);
        }
        for(int i=1; i<=3*n; i++)
        {
            if(!bejar[i]) dfs(i, 1);
        }
        if(is.size()>=n)
        {
            cout<<"IndSet"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<is[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Matching"<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}