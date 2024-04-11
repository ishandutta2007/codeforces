#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
vector<pair<pll, int> > iranyok;
vector<pair<pii, int> > query;
int ans[100009];
int n;
int test;
int darab[300009];
vector<int> irtip[100009];
int kezdet[100009];
vector<int> tipus;
pll kul(pll x, pll y)
{
    return {(ll)(x.F-y.F), (ll)(x.S-y.S)};
}
ll cross(pll a, pll b)
{
    return a.F*b.S-a.S*b.F;
}
bool compIrany(pair<pll, int> a, pair<pll, int> b)
{
    ll cr=cross(a.F, b.F);
    bool fenta=true;
    if(a.F.S<0 || (a.F.S==0 && a.F.F<0)) fenta=false;
    bool fentb=true;
    if(b.F.S<0 || (b.F.S==0 && b.F.F<0)) fentb=false;
    if(fenta==fentb)
    {
        return cr>0;
    }
    return fenta;
}
bool mas(pll x, pll y)
{
    if(x.S*y.S<0) return true;
    if(x.S==0 && y.S==0)
    {
        if(x.F*y.F<0) return true;
    }
    return cross(x, y)!=0;
}
int SQ;
bool hasonlit(pair<pii, int> x, pair<pii, int> y)
{
    int xblokk=x.F.F/SQ;
    int yblokk=y.F.F/SQ;
    if(xblokk<yblokk) return true;
    if(xblokk==yblokk)
    {
        return x.F.S<y.F.S;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int csucsok;
        cin>>csucsok;
        vector<pll> pgon(csucsok);
        for(int j=0; j<csucsok; j++)
        {
            cin>>pgon[j].F>>pgon[j].S;
        }
        for(int j=0; j<csucsok; j++)
        {
            iranyok.push_back({kul(pgon[(j+1)%csucsok], pgon[j]), i});
        }
    }
    sort(iranyok.begin(), iranyok.end(), compIrany);
    int tipuscnt=1;
    irtip[iranyok[0].S].push_back(1);
    for(int i=1; i<iranyok.size(); i++)
    {
        if(mas(iranyok[i-1].F, iranyok[i].F))
        {
            tipuscnt++;
        }
        irtip[iranyok[i].S].push_back(tipuscnt);
    }
    for(int i=1; i<=n; i++)
    {
        kezdet[i]=tipus.size();
        for(int j=0; j<irtip[i].size(); j++)
        {
            tipus.push_back(irtip[i][j]);
            //cout<<tipus.back()<<" ";
        }
        //cout<<endl;
    }
    kezdet[n+1]=tipus.size();
    cin>>test;
    for(int qq=1; qq<=test; qq++)
    {
        int LL, RR;
        cin>>LL>>RR;
        query.push_back({{kezdet[LL], kezdet[RR+1]-1}, qq});
    }
    SQ=sqrt(kezdet[n+1]);
    sort(query.begin(), query.end(), hasonlit);

    int kezdopont=0;
    int vegpont=-1;
    int cans=0;
    for(int u=0; u<query.size(); u++)
    {
        pii qu=query[u].F;
        if(u==0 || qu.F/SQ!=query[u-1].F.F/SQ)
        {
            for(int j=0; j<=kezdet[n+1]; j++) darab[j]=0;
            kezdopont=qu.F;
            vegpont=kezdopont-1;
            cans=0;
        }
        while(vegpont<qu.S)
        {
            vegpont++;
            darab[tipus[vegpont]]++;
            if(darab[tipus[vegpont]]==1) cans++;
        }
        while(kezdopont<qu.F)
        {
            darab[tipus[kezdopont]]--;
            if(darab[tipus[kezdopont]]==0) cans--;
            kezdopont++;
        }
        while(kezdopont>qu.F)
        {
            kezdopont--;
            darab[tipus[kezdopont]]++;
            if(darab[tipus[kezdopont]]==1) cans++;
        }
        ans[query[u].S]=cans;
    }
    for(int i=1; i<=test; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}