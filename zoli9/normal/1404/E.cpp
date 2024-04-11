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

char tbl[209][209];
int vid[209][209];
int hid[209][209];
int n, m;

vi G[100009];
int pr[100009];
int was[100009];

int wcnt;

bool vert(int x, int y)
{
    return vid[x][y]>0;
}

bool improve(int x)
{
    was[x]=wcnt;
    for(int nb: G[x])
    {
        if(was[nb]<wcnt)
        {
            if(pr[nb]==nb)
            {
                pr[nb]=x;
                pr[x]=nb;
                return true;
            }
            was[nb]=wcnt;
            if(improve(pr[nb]))
            {
                pr[nb]=x;
                pr[x]=nb;
                return true;
            }
        }
    }
    return false;
}

int h2=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>tbl[i][j];
            if(tbl[i][j]=='#') h2++;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(tbl[i][j]=='#' && tbl[i][j+1]=='#')
            {
                cnt++;
                vid[i][j]=cnt;
            }
        }
    }
    int rows=cnt;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(tbl[i][j]=='#' && tbl[i+1][j]=='#')
            {
                cnt++;
                hid[i][j]=cnt;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(tbl[i][j]=='#' && tbl[i+1][j]=='#')
            {
                if(vert(i, j-1))
                {
                    G[hid[i][j]].push_back(vid[i][j-1]);
                    G[vid[i][j-1]].push_back(hid[i][j]);
                }
                if(vert(i, j))
                {
                    G[hid[i][j]].push_back(vid[i][j]);
                    G[vid[i][j]].push_back(hid[i][j]);
                }
                if(vert(i+1, j-1))
                {
                    G[hid[i][j]].push_back(vid[i+1][j-1]);
                    G[vid[i+1][j-1]].push_back(hid[i][j]);
                }
                if(vert(i+1, j))
                {
                    G[hid[i][j]].push_back(vid[i+1][j]);
                    G[vid[i+1][j]].push_back(hid[i][j]);
                }
            }
        }
    }

    for(int i=1; i<=cnt; i++)
    {
        pr[i]=i;
    }
    int ans=0;
    for(int i=1; i<=rows; i++)
    {
        if(pr[i]==i)
        {
            wcnt++;
            if(improve(i)) ans++;
        }
    }
    cout<<h2-(cnt-ans)<<endl;
    return 0;
}