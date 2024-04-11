#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[200009];
bool bejar[200009];
long long ittkezd[200009];
long long gyerekek[200009];
long long barhol[200009];
long long osszesen[200009];
long long fel[200009];
int apa[200009];
void dfs(int x)
{
    bejar[x]=true;
    gyerekek[x]=1;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            dfs(sz);
            apa[sz]=x;
            gyerekek[x]+=gyerekek[sz];
            ittkezd[x]+=ittkezd[sz];
        }
    }
    ittkezd[x]+=gyerekek[x];
}
void dfs2(int x)
{
    bejar[x]=true;
    if(x==1)
    {
        fel[x]=0;
        barhol[x]=fel[x]+ittkezd[x];
    }
    else
    {
        fel[x]=((long long)(n)-gyerekek[x]+barhol[apa[x]]-ittkezd[x]-gyerekek[x]);
        barhol[x]=fel[x]+ittkezd[x];
    }
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            dfs2(sz);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    dfs(1);
    for(int i=1; i<=n; i++) bejar[i]=false;
    dfs2(1);
    long long answer=ittkezd[1];
    for(int i=2; i<=n; i++)
    {
        if(gyerekek[i]==1)
        {
            answer=max(answer, fel[i]+1);
        }
    }
    cout<<answer<<endl;
    return 0;
}