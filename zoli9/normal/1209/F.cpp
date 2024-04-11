#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
int ndb;
ll MOD=1e9+7;
vi G[600009][10];
ll ans[600009];
int q[600009];
int sk, sv;
bool w[600009];
bool last[600009];
void addedge(int a, int b, int id)
{
    vi dg;
    while(id>0)
    {
        dg.push_back(id%10);
        id/=10;
    }
    reverse(dg.begin(), dg.end());
    int dd=dg.size();
    int lastnode=a;
    for(int i=0; i<dd; i++)
    {
        if(i+1==dd)
        {
            G[lastnode][dg[i]].push_back(b);
            G[b][dg[dd-1-i]].push_back(lastnode);
        }
        else
        {
            ndb++;
            G[lastnode][dg[i]].push_back(ndb);
            G[ndb][dg[dd-1-i]].push_back(lastnode);
            lastnode=ndb;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ndb=n;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        addedge(a, b, i);
    }
    sk=1;
    sv=1;
    q[1]=1;
    w[1]=true;
    last[1]=true;
    while(sk<=sv)
    {
        for(int nxt=0; nxt<10; nxt++)
        {
            int cnt=sk;
            while(1)
            {
                for(int sz: G[q[cnt]][nxt])
                {
                    if(!w[sz])
                    {
                        //cout<<"* "<<sz<<" "<<nxt<<endl;
                        ans[sz]=(10*ans[q[cnt]]+nxt)%MOD;
                        w[sz]=true;
                        sv++;
                        q[sv]=sz;
                    }
                }
                if(last[cnt]) break;
                cnt++;
            }
            last[sv]=true;
        }
        while(!last[sk]) sk++;
        sk++;
    }
    for(int i=2; i<=n; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}