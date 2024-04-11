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
int infi=1e6;
ll infi2=1e15;
int n, m;
ll MOD=998244353;
vector<int> G[400009];
struct pont
{
    int id;
    int moves;
    int tav;
    bool operator< (const pont & p) const
    {
        return tav>p.tav;
    }
};
pont x, y;
priority_queue<pont> q;
int t[400009][20];
//int bestt[400009];
bool visited[400009][20];


struct pont2
{
    int id;
    ll tav;
    bool operator< (const pont2 & p) const
    {
        return tav>p.tav;
    }
};
pont2 x2, y2;
priority_queue<pont2> q2;
ll t2[400009];
bool vis2[400009];


int flipped(int x)
{
    if(x>n) return x-n;
    return x+n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=2*n; i++) for(int j=0; j<20; j++) t[i][j]=-1;
    //for(int i=1; i<=2*n; i++) bestt[i]=-1;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b+n].push_back(a+n);
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    x.id=1;
    x.moves=0;
    x.tav=0;
    t[1][0]=0;
    //bestt[1]=0;
    q.push(x);
    while(q.size()>0)
    {
        x=q.top();
        q.pop();
        if(!visited[x.id][x.moves])
        {
            visited[x.id][x.moves]=true;
            for(int i=0; i<G[x.id].size(); i++)
            {
                int sz=G[x.id][i];
                if(!visited[sz][x.moves])
                {
                    if(t[sz][x.moves]==-1 || x.tav+1<t[sz][x.moves])
                    {
                        //if(bestt[sz]>=0 && bestt[sz]<=x.tav+1) continue;
                        t[sz][x.moves]=x.tav+1;
                        y.id=sz;
                        y.moves=x.moves;
                        y.tav=t[sz][x.moves];
                        //if(bestt[sz]==-1) bestt[sz]=x.tav+1;
                        //else bestt[sz]=min(bestt[sz], x.tav+1);
                        q.push(y);
                    }
                }
            }
            int ff=flipped(x.id);
            if(x.tav+(1<<x.moves)>500000) continue;
            if(!visited[ff][x.moves+1])
            {
                if(t[ff][x.moves+1]==-1 || x.tav+(1<<x.moves)<t[ff][x.moves+1])
                {
                    //if(bestt[ff]>=0 && bestt[ff]<=x.tav+(1<<x.moves)) continue;
                    t[ff][x.moves+1]=x.tav+(1<<x.moves);
                    y.id=ff;
                    y.moves=x.moves+1;
                    y.tav=t[ff][x.moves+1];
                    //if(bestt[ff]==-1) bestt[ff]=x.tav+(1<<x.moves);
                    //else bestt[ff]=min(bestt[ff], x.tav+(1<<x.moves));
                    q.push(y);
                }
            }
        }
    }
    int res1=infi;
    for(int j=0; j<20; j++) if(t[n][j]>=0 && t[n][j]<res1) res1=t[n][j];
    int res2=infi;
    for(int j=0; j<20; j++) if(t[2*n][j]>=0 && t[2*n][j]<res1) res2=t[2*n][j];
    //cout<<bestt[n]<<" "<<bestt[2*n]<<endl;
    if(min(res1, res2)<infi)
    {
        cout<<(min(res1, res2))<<endl;
        return 0;
    }

    for(int i=1; i<=2*n; i++) t2[i]=-1;
    x2.id=1;
    x2.tav=0;
    t2[1]=0;
    q2.push(x2);

    while(q2.size()>0)
    {
        x2=q2.top();
        q2.pop();
        if(!vis2[x2.id])
        {
            vis2[x2.id]=true;
            for(int i=0; i<G[x2.id].size(); i++)
            {
                int sz=G[x2.id][i];
                if(!vis2[sz])
                {
                    if(t2[sz]==-1 || x2.tav+1<t2[sz])
                    {
                        t2[sz]=x2.tav+1;
                        y2.id=sz;
                        y2.tav=t2[sz];
                        q2.push(y2);
                    }
                }
            }
            int ff=flipped(x2.id);
            if(!vis2[ff])
            {
                if(t2[ff]==-1 || x2.tav+400000<t2[ff])
                {
                    t2[ff]=x2.tav+400000;
                    y2.id=ff;
                    y2.tav=t2[ff];
                    q2.push(y2);
                }
            }
        }
    }
    ll maxbest=min(t2[n], t2[2*n]);
    ll ones=maxbest%400000;
    ll trp=maxbest/400000;
    ll cost=1;
    ll ans=0;
    for(int i=1; i<=trp; i++)
    {
        ans=(ans+cost)%MOD;
        cost=(2*cost)%MOD;
    }
    ans=(ans+ones)%MOD;
    cout<<ans<<endl;
    return 0;
}