#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
int deg[maxn];
int u[maxn],v[maxn];

vector<int> G[maxn];

bool vis[maxn];

void dfs(int i,int fa=0)    {
    vis[i]=1;
    for (int j:G[i])    {
        if (fa==j) continue;
        dfs(j,i);
    }
}

int main()  {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        scanf("%d%d",u+k,v+k);
    }

    for (int i=1;i<=n;++i) vis[i]=0;

    for (int t=0;t<n/2;++t) {
        for (int i=1;i<=n;++i) G[i].clear();
        for (int k=1;k<n;++k)
            if (!vis[u[k]]&&!vis[v[k]]) {
                G[u[k]].push_back(v[k]);
                G[v[k]].push_back(u[k]);
            }
        int k=-1;

        vector<int> one;
        for (int i=1;i<=n;++i)  {
            if (vis[i]) continue;
            if (G[i].size()>1)  {
                k=i;
                break;
            } else one.push_back(i);
        }

        if (k==-1)   {
            assert(one.size()<=2);
            if (one.size()==1)
                cout<<"! "<<one.back()<<endl;
            else    {
                cout<<"? "<<one[0]<<" "<<one[1]<<endl;
                int a;
                cin>>a;
                cout<<"! "<<a<<endl;
            }
            return 0;
        } else  {
            cout<<"? "<<G[k][0]<<" "<<G[k][1]<<endl;
            int a;
            cin>>a;
            if (a==k)   {
                dfs(G[k][0],k);
                dfs(G[k][1],k);
            } else  {
                dfs(k,a);
            }
        }
    }

    int cnt=0,k=0;
    for (int i=1;i<=n;++i)
        if (!vis[i])
            k=i,++cnt;
    assert(cnt==1);
    cout<<"! "<<k<<endl;
    return 0;
}