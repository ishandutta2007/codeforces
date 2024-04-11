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
ll w;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

ll infi=1e18;

ll table[2009][2009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>w;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>table[i][j];
        }
    }
    queue<pii> Q;
    vector<vll> ddist(n+1, vll(m+1, infi));
    Q.push({1, 1});
    ddist[1][1]=0;
    while(Q.size()>0)
    {
        pii cur=Q.front();
        Q.pop();
        for(int d=0; d<4; d++)
        {
            int nx=cur.F+dx[d];
            int ny=cur.S+dy[d];
            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            if(table[nx][ny]<0) continue;
            if(ddist[nx][ny]==infi)
            {
                ddist[nx][ny]=ddist[cur.F][cur.S]+w;
                Q.push({nx, ny});
            }
        }
    }
    vector<vll> sdist(n+1, vll(m+1, infi));
    Q.push({n, m});
    sdist[n][m]=0;
    while(Q.size()>0)
    {
        pii cur=Q.front();
        Q.pop();
        for(int d=0; d<4; d++)
        {
            int nx=cur.F+dx[d];
            int ny=cur.S+dy[d];
            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            if(table[nx][ny]<0) continue;
            if(sdist[nx][ny]==infi)
            {
                sdist[nx][ny]=sdist[cur.F][cur.S]+w;
                Q.push({nx, ny});
            }
        }
    }
    ll bestd=infi;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(table[i][j]>0 && ddist[i][j]!=infi)
            {
                bestd=min(bestd, ddist[i][j]+table[i][j]);
            }
        }
    }
    ll bests=infi;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(table[i][j]>0 && sdist[i][j]!=infi)
            {
                bests=min(bests, sdist[i][j]+table[i][j]);
            }
        }
    }
    ll answer=ddist[n][m];
    answer=min(answer, bestd+bests);
    if(answer>=infi)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<answer<<'\n';
    }




    return 0;
}