#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int dist1;
vi G[200009];
int si[200009];
int heavy[200009];
bool was[200009];
int lev[200009];
void dfs(int x)
{
    was[x]=true;
    si[x]++;
    for(int sz: G[x])
    {
        if(!was[sz])
        {
            lev[sz]=lev[x]+1;
            dfs(sz);
            si[x]+=si[sz];
            if(heavy[x]==0 || si[sz]>si[heavy[x]]) heavy[x]=sz;
        }
    }
}
void sch(int x)
{
    if(si[x]==1 || lev[x]==dist1)
    {
        cout<<"! "<<x<<endl;
        fflush(stdout);
        exit(0);
    }
    int leaf=x;
    while(si[leaf]>1) leaf=heavy[leaf];
    cout<<"d "<<leaf<<endl;
    fflush(stdout);
    int dl;
    cin>>dl;
    if(dl==0)
    {
        cout<<"! "<<leaf<<endl;
        fflush(stdout);
        exit(0);
    }
    int lcalev=(dist1+lev[leaf]-dl)/2;
    while(lev[x]+1<lcalev) x=heavy[x];
    cout<<"s "<<x<<endl;
    fflush(stdout);
    int direction;
    cin>>direction;
    sch(direction);
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
    cout<<"d 1"<<endl;
    fflush(stdout);
    cin>>dist1;
    if(dist1==0)
    {
        cout<<"! 1"<<endl;
        fflush(stdout);
        return 0;
    }
    sch(1);
    return 0;
}