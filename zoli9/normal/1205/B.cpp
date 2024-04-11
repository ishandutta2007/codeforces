#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
vector<ll> vanbit[60];
int nn;
map<ll, int> idx;
int n;
bool G[209][209];
int sor[209];
int szint[209];
int bejarcnt;
int bejar[209];
int bfs(int x, int y)
{
    int sk=1;
    int sv=1;
    sor[sk]=x;
    bejarcnt++;
    bejar[x]=bejarcnt;
    szint[x]=0;
    while(sk<=sv)
    {
        int akt=sor[sk];
        for(int i=1; i<=n; i++)
        {
            if(G[akt][i] && bejar[i]<bejarcnt)
            {
                bejar[i]=bejarcnt;
                szint[i]=szint[akt]+1;
                sv++;
                sor[sv]=i;
                //cout<<x<<" : "<<y<<" --- "<<szint[i]<<endl;
                if(i==y) return szint[i]+1;
            }
        }
        sk++;
    }
    return -1;
}
int ans=-1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nn;
    for(int i=1; i<=nn; i++)
    {
        ll szam;
        cin>>szam;
        ll a=szam;
        for(int j=0; j<60; j++)
        {
            if(a%2) vanbit[j].push_back(szam);
            a/=2;
        }
    }
    for(int i=0; i<60; i++)
    {
        if(vanbit[i].size()>2)
        {
            cout<<3<<endl;
            return 0;
        }
        if(vanbit[i].size()==2)
        {
            if(vanbit[i][0]!=vanbit[i][1])
            {
                if(idx[vanbit[i][0]]<=0)
                {
                    n++;
                    idx[vanbit[i][0]]=n;
                }
                if(idx[vanbit[i][1]]<=0)
                {
                    n++;
                    idx[vanbit[i][1]]=n;
                }
                int c1=idx[vanbit[i][0]];
                int c2=idx[vanbit[i][1]];
                G[c1][c2]=true;
                G[c2][c1]=true;
            }
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<G[i][j];
        }
        cout<<endl;
    }*/
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(G[i][j])
            {
                G[i][j]=false;
                G[j][i]=false;
                int uj=bfs(i, j);
                if(uj>0 && (ans==-1 || uj<ans)) ans=uj;
                G[i][j]=true;
                G[j][i]=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}