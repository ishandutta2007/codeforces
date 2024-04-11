#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int n, m;
vi G[200009];
vi gy[200009];
bool was[200009];
int fok[200009];
int apa[200009];
int ans[200009];
queue<int> levelek;
void dfs(int x)
{
    was[x]=true;
    for(int sz: G[x])
    {
        if(!was[sz])
        {
            apa[sz]=x;
            gy[x].push_back(sz);
            fok[x]++;
            fok[sz]++;
            dfs(sz);
        }
    }
    if(fok[x]==1) levelek.push(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            gy[i].clear();
            fok[i]=0;
            apa[i]=0;
            was[i]=false;
            ans[i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            int aa, bb;
            cin>>aa>>bb;
            G[aa].push_back(bb);
            G[bb].push_back(aa);
        }
        dfs(1);
        while(levelek.size()>0)
        {
            int le=levelek.front();
            levelek.pop();
            if(ans[le]>0)
            {
                fok[apa[le]]--;
                if(fok[apa[le]]==1)
                {
                    if(apa[le]!=1) levelek.push(apa[le]);
                }
                continue;
            }
            ans[apa[le]]=2;
            for(int gyerek: gy[apa[le]])
            {
                if(ans[gyerek]==0) ans[gyerek]=1;
            }
            if(ans[apa[apa[le]]]==0) ans[apa[apa[le]]]=1;
            fok[apa[le]]--;
            if(fok[apa[le]]==1)
            {
                if(apa[le]!=1) levelek.push(apa[le]);
            }
        }
        if(ans[1]==0) ans[1]=2;
        vi valasz;
        for(int i=1; i<=n; i++) if(ans[i]==2) valasz.push_back(i);
        cout<<valasz.size()<<endl;
        for(int i: valasz) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}