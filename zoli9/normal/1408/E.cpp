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
int m, n;
ll a[100009];
ll b[100009];


int mag[500009];
int dad[500009];

void unio(int x, int y)
{
    if(mag[x]<mag[y]) dad[x]=y;
    else
    {
        dad[y]=x;
        mag[x]++;
    }
}

int holvan(int x)
{
    if(dad[x]==x) return x;
    return dad[x]=holvan(dad[x]);
}

ll totalsum=0;

vector<pair<ll, pii> > edges;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1; i<=m; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    for(int i=1; i<=n+m; i++)
    {
        mag[i]=1;
        dad[i]=i;
    }

    for(int i=1; i<=m; i++)
    {
        int db;
        cin>>db;
        for(int j=1; j<=db; j++)
        {
            int x;
            cin>>x;
            ll cc=a[i]+b[x];
            edges.push_back({cc, {i, m+x}});
            //cout<<"e: "<<cc<<" "<<i<<" "<<m+x<<endl;
            totalsum+=cc;
        }
    }

    ll mincost=0;
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); i++)
    {
        int x=holvan(edges[i].S.F);
        int y=holvan(edges[i].S.S);
        if(x!=y)
        {
            mincost+=edges[i].F;
            unio(x, y);
        }
    }
    //cout<<mincost<<endl;
    cout<<totalsum-mincost<<endl;


    return 0;
}