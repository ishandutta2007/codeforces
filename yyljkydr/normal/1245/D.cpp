#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n;

int d[N],k[N],x[N],y[N];

int pre[N];

bool vis[N];

vector<int>blt;

vector<pair<int,int> >edg;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
        cin>>d[i],pre[i]=-1;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(p==-1||d[j]<d[p]))
                p=j;
        assert(p!=-1);
        if(pre[p]==-1)
            blt.push_back(p);
        else
            edg.push_back({pre[p],p});
        vis[p]=1;
        ans+=d[p];
        for(int j=1;j<=n;j++)
        {
            if((k[p]+k[j])*(abs(x[p]-x[j])+abs(y[p]-y[j]))<d[j])
                pre[j]=p,d[j]=(k[p]+k[j])*(abs(x[p]-x[j])+abs(y[p]-y[j]));
        }
    }
    cout<<ans<<"\n";
    cout<<(int)blt.size()<<"\n";
    for(auto x:blt)
        cout<<x<<" ";
    cout<<"\n";
    cout<<(int)edg.size()<<"\n";
    for(auto [x,y]:edg)
        cout<<x<<" "<<y<<"\n";
}