#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int n, m;
vi G[200009];
bool vis[200009];
bool vis2[200009];
int dad[200009];
pii p;

void dfs(int x)
{
    vis[x]=true;
    for(int nb: G[x])
    {
        if(!vis[nb])
        {
            dad[nb]=x;
            dfs(nb);
        }
        else if(nb!=dad[x])
        {
            if(p.F==0) p={x, nb};
            return;
        }
    }
}

vi find_cycle()
{
    dfs(1);
    //cout<<p.F<<" - "<<p.S<<endl;
    //cout<<"dfs"<<endl;
    vi res;
    while(p.F!=p.S)
    {
        //cout<<p.F<<" ::: "<<p.S<<endl;
        res.push_back(p.F);
        p.F=dad[p.F];
    }
    res.push_back(p.S);
    return res;
}

int dfs2(int x)
{
    vis2[x]=true;
    int res=1;
    for(int nb: G[x])
    {
        if(!vis2[nb])
        {
            res+=dfs2(nb);
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        p={0, 0};
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            vis[i]=false;
            vis2[i]=false;
            dad[i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ll NN=n;
        ll ans=NN*(NN-1);
        vi cc=find_cycle();
        /*cout<<cc.size()<<endl;
        for(int x: cc) cout<<x<<" . ";
        cout<<endl;*/
        for(int x: cc) vis2[x]=true;
        for(int x: cc)
        {
            ll cur=dfs2(x);
            cur*=(cur-1);
            cur/=2;
            ans-=cur;
        }
        cout<<ans<<'\n';
    }
    return 0;
}