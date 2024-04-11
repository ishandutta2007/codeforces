#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
int test;

int n;
ll m, c, c0, c1;
set<pll> s;
vector<pair<ll, pll> > fr;
ll ans=0;
void inserting(pll p)
{
    auto itf=s.lower_bound({p.F, 0});
    if(itf==s.end() || (itf->F)>p.F) s.insert(p);
    else
    {
        ll aval=itf->S;
        s.erase(itf);
        s.insert({p.F, p.S+aval});
    }
}
void play(ll t)
{
    if(c0>=t)
    {
        c0-=t;
        return;
    }
    else
    {
        t-=c0;
        c0=0;
    }
    auto it=s.begin();
    while(1)
    {
        if(it==s.end())
        {
            ans=-1;
            return;
        }
        pll f=*it;
        if(t<=f.S)
        {
            ans+=(t*f.F);
            c1-=t;
            s.erase(it);
            if(t!=f.S) inserting({f.F, f.S-t});
            break;
        }
        ans+=(f.S*f.F);
        c1-=f.S;
        t-=f.S;
        s.erase(it++);
    }
}
void addfr(pll f)
{
    inserting(f);
    c1+=f.S;
    if(s.empty()) return;
    if(c1<=c-c0) return;
    auto it=s.end();
    it--;
    while(1)
    {
        pll p=*it;
        if(c1-p.S<=c-c0)
        {
            s.erase(it);
            if(c1-p.S!=c-c0) inserting({p.F, c-c0-(c1-p.S)});
            c1=c-c0;
            break;
        }
        c1-=p.S;
        s.erase(it--);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m>>c>>c0;
        s.clear();
        fr.resize(n);
        c1=0;
        ans=0;
        for(int i=0; i<n; i++)
        {
            cin>>fr[i].F>>fr[i].S.S>>fr[i].S.F;
        }
        sort(fr.begin(), fr.end());
        for(int i=0; i<n; i++)
        {
            if(i==0) play(fr[i].F);
            else play(fr[i].F-fr[i-1].F);
            if(ans==-1)
            {
                cout<<-1<<endl;
                break;
            }
            addfr(fr[i].S);
        }
        if(ans==-1) continue;
        if(n==0) play(m);
        else play(m-fr[n-1].F);
        cout<<ans<<endl;
    }


    return 0;
}