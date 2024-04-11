#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vector<int> G[1009];
vector<pair<pii, int> > ans;
int bsize[1009];
int dad[1009];
bool was[1009];
void dfs(int x)
{
    was[x]=true;
    for(int sz: G[x])
    {
        if(!was[sz])
        {
            dfs(sz);
            bsize[x]+=bsize[sz];
            dad[sz]=x;
        }
    }
    bsize[x]++;
}
vi as, bs;
int asum, bsum, asi, bsi;
int group[1009];
bool sicmp(int x, int y)
{
    return bsize[x]>bsize[y];
}
void dfsa(int x, int st, int en, int va)
{
    was[x]=true;
    ans.push_back({{x, dad[x]}, as[st]-va});
    int cnt=st+1;
    va=as[st];
    for(int sz: G[x])
    {
        if(was[sz]) continue;
        dfsa(sz, cnt, en, va);
        cnt+=bsize[sz];
    }
}
void dfsb(int x, int st, int en, int va)
{
    was[x]=true;
    ans.push_back({{x, dad[x]}, bs[st]-va});
    int cnt=st+1;
    va=bs[st];
    for(int sz: G[x])
    {
        if(was[sz]) continue;
        dfsb(sz, cnt, en, va);
        cnt+=bsize[sz];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    int centroid=1;
    for(int i=1; i<=n; i++) was[i]=false;
    while(1)
    {
        was[centroid]=true;
        bool changed=false;
        for(int sz: G[centroid])
        {
            if(was[sz]) continue;
            if(bsize[sz]>n/2)
            {
                centroid=sz;
                changed=true;
                break;
            }
        }
        if(!changed) break;
    }
    for(int i=1; i<=n; i++)
    {
        was[i]=false;
        bsize[i]=0;
    }
    dfs(centroid);
    //cout<<centroid<<endl;
    sort(G[centroid].begin(), G[centroid].end(), sicmp);
    for(int sz: G[centroid])
    {
        if(asum<=bsum)
        {
            group[sz]=1;
            asum+=bsize[sz];
            asi++;
        }
        else
        {
            group[sz]=2;
            bsum+=bsize[sz];
            bsi++;
        }
    }
    for(int i=1; i<=asum; i++)
    {
        as.push_back(i);
    }
    for(int i=1; i<=bsum; i++)
    {
        bs.push_back((asum+1)*i);
    }
    for(int i=1; i<=n; i++)
    {
        was[i]=false;
    }
    was[centroid]=true;
    int acnt=0;
    int bcnt=0;
    for(int sz: G[centroid])
    {
        if(group[sz]==1)
        {
            dfsa(sz, acnt, acnt+bsize[sz], 0);
            acnt+=bsize[sz];
        }
        else
        {
            dfsb(sz, bcnt, bcnt+bsize[sz], 0);
            bcnt+=bsize[sz];
        }
    }
    //cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].F.F<<" "<<ans[i].F.S<<" "<<ans[i].S<<endl;
    }

    return 0;
}