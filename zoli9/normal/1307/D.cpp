#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, k;
bool spec[200009];
vi G[200009];
int d1[200009];
int dn[200009];
queue<int> q;
bool bejar[200009];
vector<int> s1;
int maxi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++)
    {
        int spe;
        cin>>spe;
        spec[spe]=true;
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    q.push(1);
    bejar[1]=true;
    if(spec[1]) s1.push_back(1);
    while(q.size()>0)
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                bejar[sz]=true;
                q.push(sz);
                d1[sz]=d1[akt]+1;
                if(spec[sz])
                {
                    s1.push_back(sz);
                }
            }
        }
    }
    for(int i=1; i<=n; i++) bejar[i]=false;
    q.push(n);
    bejar[n]=true;
    while(q.size()>0)
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                bejar[sz]=true;
                q.push(sz);
                dn[sz]=dn[akt]+1;
            }
        }
    }
    int ans=0;
    maxi=dn[s1[k-1]];
    for(int i=k-2; i>=0; i--)
    {
        int cans=min(d1[n], d1[s1[i]]+1+maxi);
        ans=max(ans, cans);
        maxi=max(maxi, dn[s1[i]]);
    }
    cout<<ans<<endl;




    return 0;
}