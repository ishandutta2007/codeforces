#include <bits//stdc++.h>
using namespace std;
#define F first
#define S second
vector<pair< long long, pair<long long, long long> > > kezdes; //day, tipus, cost
vector<pair<long long, long long> > vegzes[100009];
vector<pair<long long, long long> > veg[100009];

set<pair<long long, long long> > yv;
int n, m;
long long k;
int cnt;
long long ans=-1;
long long costk[100009];
long long costv[100009];
long long csum;
int darabjo;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        long long day, kk, vv, cost;
        cin>>day>>kk>>vv>>cost;
        if(vv==0)
        {
            kezdes.push_back({day, {kk, cost}});
        }
        else
        {
            vegzes[vv].push_back({-day, cost});
        }
    }
    for(int i=1; i<=n; i++)
    {
        //sort(kezdes[i].begin(), kezdes[i].end());
        if(vegzes[i].size()==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        sort(vegzes[i].begin(), vegzes[i].end());
    }
    for(int i=1; i<=n; i++)
    {
        if(vegzes[i].size()==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        vegzes[i][0].F*=(-1);
        veg[i].push_back(vegzes[i][0]);
        for(int j=1; j<vegzes[i].size(); j++)
        {
            if(vegzes[i][j].S<veg[i].back().S)
            {
                vegzes[i][j].F*=(-1);
                veg[i].push_back(vegzes[i][j]);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        yv.insert({veg[i].back().F, i});
        costv[i]=veg[i].back().S;
        csum+=costv[i];
        veg[i].pop_back();
    }
    sort(kezdes.begin(), kezdes.end());
    while(1)
    {
        pair<long long, long long> vegveg=*yv.begin();
        //cout<<"vegveg: "<<vegveg.F<<" "<<vegveg.S<<endl;
        while(cnt<kezdes.size() && kezdes[cnt].F<vegveg.F-k)
        {
            //cout<<"kezel: "<<kezdes[cnt].F<<endl;
            if(costk[kezdes[cnt].S.F]==0)
            {
                //cout<<"dbjo: "<<kezdes[cnt].S.F<<endl;
                costk[kezdes[cnt].S.F]=kezdes[cnt].S.S;
                darabjo++;
                csum+=kezdes[cnt].S.S;
            }
            else if(costk[kezdes[cnt].S.F]>kezdes[cnt].S.S)
            {
                csum-=costk[kezdes[cnt].S.F];
                csum+=kezdes[cnt].S.S;
                costk[kezdes[cnt].S.F]=kezdes[cnt].S.S;
            }
            cnt++;
        }
        if(darabjo==n)
        {
            if(ans==-1) ans=csum;
            else if(ans>csum) ans=csum;
        }
        if(veg[vegveg.S].size()==0) break;
        pair<long long, long long> uj;
        uj.F=veg[vegveg.S].back().F;
        uj.S=vegveg.S;
        yv.erase(yv.begin());
        yv.insert(uj);
        csum-=costv[vegveg.S];
        costv[vegveg.S]=veg[vegveg.S].back().S;
        csum+=costv[vegveg.S];
        veg[vegveg.S].pop_back();
    }
    cout<<ans<<endl;
    return 0;
}