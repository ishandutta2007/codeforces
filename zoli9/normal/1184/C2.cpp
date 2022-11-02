#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, radius;
vector<pair<pair<int, int>, int> > ev;
int plusz=2000000;
int maxn=4000000;
int m[10000009];
int lazy[10000009];
void hozzaad(int cs, int k, int v, int x, int y, int d)
{
    if(lazy[cs]!=0)
    {
        m[cs]+=lazy[cs];
        if(k!=v)
        {
            lazy[2*cs]+=lazy[cs];
            lazy[2*cs+1]+=lazy[cs];
        }
        lazy[cs]=0;
    }
    if(x>y) return;
    if(v<x || y<k) return;
    if(x<=k && v<=y)
    {
        m[cs]+=d;
        if(k!=v)
        {
            lazy[2*cs]+=d;
            lazy[2*cs+1]+=d;
        }
        return;
    }
    hozzaad(2*cs, k, (k+v)/2, x, y, d);
    hozzaad(2*cs+1, (k+v)/2+1, v, x, y, d);
    m[cs]=max(m[2*cs], m[2*cs+1]);
}
int kerdez()
{
    return m[1];
}

void novel(int x, int y, int d)
{
    x=max(x, -2000000);
    y=min(y, 2000000);
    hozzaad(1, 0, maxn, x+plusz, y+plusz, d);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>radius;
    for(int i=1; i<=n; i++)
    {
        int xx, yy;
        cin>>xx>>yy;
        ev.push_back({{xx-yy-2*radius, 0}, xx+yy});
        ev.push_back({{xx-yy, 1}, xx+yy});
    }
    sort(ev.begin(), ev.end());
    int maxi=0;
    for(pair<pair<int, int>, int> e: ev)
    {
        if(e.F.S==0)
        {
            novel(e.S-radius, e.S+radius, 1);
            maxi=max(maxi, kerdez());
        }
        else
        {
            novel(e.S-radius, e.S+radius, -1);
        }
    }
    cout<<maxi<<endl;
    return 0;
}