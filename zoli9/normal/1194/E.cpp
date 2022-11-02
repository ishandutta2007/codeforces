#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll ans=0;
int maxcor=10000;
vector<pair<int, pii> > fugg;
vector<pair<int, pii> > viz;
vector<pair<int, pii> > vizjo;
bool fuggnov(pair<int, pii> p1, pair<int, pii> p2)
{
    return p1.F<p2.F;
}
bool viznov(pair<int, pii> p1, pair<int, pii> p2)
{
    return p1.S.S<p2.S.S;
}
int m[100009];
void ini(int cs, int k, int v)
{
    m[cs]=0;
    if(k==v) return;
    ini(2*cs, k, (k+v)/2);
    ini(2*cs+1, (k+v)/2+1, v);
}
void modosit(int cs, int k, int v, int x, int dd)
{
    if(v<x || x<k) return;
    m[cs]+=dd;
    if(k==v) return;
    modosit(2*cs, k, (k+v)/2, x, dd);
    modosit(2*cs+1, (k+v)/2+1, v, x, dd);
}
int kerdez(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return 0;
    if(x<=k && v<=y) return m[cs];
    return kerdez(2*cs, k, (k+v)/2, x, y)+kerdez(2*cs+1, (k+v)/2+1, v, x, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(y2<y1) swap(y1, y2);
        if(x2<x1) swap(x1, x2);
        if(x1==x2)
        {
            fugg.push_back({x1, {y1, y2}});
        }
        else
        {
            viz.push_back({y1, {x1, x2}});
        }
    }
    sort(fugg.begin(), fugg.end(), fuggnov);
    sort(viz.begin(), viz.end(), viznov);
    for(int u=0; u<fugg.size(); u++)
    {
        pair<int, pii> ff=fugg[u];
        vizjo.clear();
        ini(1, 0, maxcor);
        for(pair<int, pii> vv: viz)
        {
            if(vv.S.F<=ff.F && ff.F<=vv.S.S && ff.S.F<=vv.F && vv.F<=ff.S.S)
            {
                vizjo.push_back(vv);
                modosit(1, 0, maxcor, vv.F+5000, 1);
            }
        }
        int vizcnt=0;
        for(int u2=u+1; u2<fugg.size(); u2++)
        {
            pair<int, pii> ff2=fugg[u2];
            while(vizcnt<vizjo.size() && vizjo[vizcnt].S.S<ff2.F)
            {
                modosit(1, 0, maxcor, vizjo[vizcnt].F+5000, -1);
                vizcnt++;
            }
            int metszetek=kerdez(1, 0, maxcor, ff2.S.F+5000, ff2.S.S+5000);
            ll plusz=metszetek*(metszetek-1)/2;
            ans+=plusz;
        }
    }
    cout<<ans<<endl;
    return 0;
}