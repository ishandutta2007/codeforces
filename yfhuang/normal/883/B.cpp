#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int N=410000;
int r[N],x[N]={0},mxx[N];
int du[N],n;
vector<int>nex[N],pre[N];
queue<int>q;
pair<int, int >p[N],j;
priority_queue<pair<int,int>>q2;
int app[N],len=0,K;
int mx(int i)
{
    int tmp=2*n;
    for(int j=0;j<nex[i].size();j++)tmp=min(x[nex[i][j]]-1,tmp);
    return tmp;
}
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first!=p2.first)return p1.first<p2.first;
    return mxx[p1.second]>mxx[p2.second];
}
bool bfs()
{
    for(int i=1;i<=n;i++){
        if(du[i]==0)q.push(i);
        x[i]=r[i];
        if(x[i]==0)x[i]=1;
    }
    while(!q.empty())
    {
        int i=q.front();q.pop();
        if(r[i]>0&&x[i]>r[i])return 0;
        for(int j=0;j<nex[i].size();j++)
        {
            int k=nex[i][j];
            du[k]--;
            x[k]=max(x[k],x[i]+1);
            if(du[k]==0)q.push(k);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(du[i]>0)return 0;
        if(x[i]>K)return 0;
        app[x[i]]++;
        p[i]=make_pair(x[i], i);
        mxx[i]=mx(i);
    }
    return 1;
}
int d[N]={0},del[N];
void dell(int t)
{
    if(del[t])return ;
    del[t]=1;
    for(int k=0;k<pre[t].size();k++)
    {
        int i=pre[t][k];
        d[i]--;
        if(d[i]==0&&r[i]==0)q2.push(make_pair(x[i],i));
    }
}
int rk=0;
int main()
{
    int m,k,u,v;
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        nex[v].push_back(u);
        pre[u].push_back(v);
        du[u]++;
        d[v]++;
    }
    if(!bfs()){cout<<-1<<endl;return 0;}
    for(int i=1;i<=n;i++)if(d[i]==0&&r[i]==0)
    {
        q2.push(make_pair(x[i],i));
    }
    int len=n;
    sort(p+1,p+len+1,cmp);
    for(int i=K;i>=1;i--)if(app[i]==0)
    {
        while(len>0&&p[len].first>i)
        {
            dell(p[len].second);
            len--;
        }
        while(!q2.empty()&&q2.top().first>i){
            q2.pop();
            dell(q2.top().second);
        }
        if(q2.empty()){cout<<-1;return 0;}
        j=q2.top();q2.pop();
        x[j.second]=i;
        app[j.first]--;
        dell(j.second);
    }
    for(int i=1;i<=n;i++)cout<<x[i]<<" ";
}
/*
 2 1 1
 0 0
 2 1
 
 */