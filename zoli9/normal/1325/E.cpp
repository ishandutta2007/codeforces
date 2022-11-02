#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
vi pr;
int a[100009];
bool composite[1000009];
int getid[1000009];
vi G[100009];
int lev[100009];
int dad[100009];

void eratosthenes(int maxn)
{
    getid[1]=0;
    pr.push_back(1);
    for(int i=2; i<=maxn; i++)
    {
        if(composite[i]) continue;
        getid[i]=pr.size();
        pr.push_back(i);
        for(int j=2*i; j<=maxn; j+=i) composite[j]=true;
    }
}
void make_edges()
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1)
        {
            cout<<1<<endl;
            exit(0);
        }
        int sqrta=sqrt(a[i]);
        if(a[i]==sqrta*sqrta)
        {
            cout<<1<<endl;
            exit(0);
        }
        int x=a[i];
        int p1=1;
        int p2=1;
        for(int p: pr)
        {
            if(p==1) continue;
            if(x==1 || (ll)p*(ll)p>x) break;
            if(x%p==0)
            {
                int pcnt=0;
                while(x%p==0)
                {
                    pcnt++;
                    x/=p;
                }
                if(pcnt%2==1)
                {
                    if(p1==1) p1=p;
                    else p2=p;
                }
            }
        }
        if(x>1) p2=x;
        int e1=getid[p1];
        int e2=getid[p2];
        G[e1].push_back(e2);
        G[e2].push_back(e1);

    }
    for(int i=0; i<pr.size(); i++)
    {
        sort(G[i].begin(), G[i].end());
        for(int j=1; j<G[i].size(); j++)
        {
            if(G[i][j-1]==G[i][j])
            {
                cout<<2<<endl;
                exit(0);
            }
        }
    }
}
int bfs(int start)
{
    queue<int> q;
    vector<bool> visited(pr.size(), false);
    q.push(start);
    visited[start]=true;
    lev[start]=0;
    dad[start]=-1;

    int res=-1;
    while(q.size()>0)
    {
        int cur=q.front();
        q.pop();
        for(int ne: G[cur])
        {
            if(visited[ne])
            {
                if(dad[cur]==ne) continue;
                if(res==-1 || res>lev[cur]+lev[ne]+1)
                {
                    res=lev[cur]+lev[ne]+1;
                }
            }
            else
            {
                q.push(ne);
                visited[ne]=true;
                lev[ne]=lev[cur]+1;
                dad[ne]=cur;
            }
        }
    }
    //cout<<pr[start]<<" r: "<<res<<" res"<<endl;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    eratosthenes(1000000);
    make_edges();
    int answer=-1;
    for(int i=0; i<pr.size(); i++)
    {
        if(pr[i]>1000) break;
        int cycle_len=bfs(i);
        if(answer==-1 || (cycle_len>=0 && cycle_len<answer))
        {
            answer=cycle_len;
        }
    }
    cout<<answer<<endl;
    return 0;
}