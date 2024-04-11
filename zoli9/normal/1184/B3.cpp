#include <bits/stdc++.h>
using namespace std;
int n, m;
int tav[109][109];
int s, b, KK;
long long legjobb[109][109]; // csucs, tav
long long profit[100009];
long long infi=1e18;
struct BaseShip
{
    int lo;
    int pwr;
    int fuel;
    int cost;
    int tp;
    int idx;
    bool operator<(const BaseShip & BS) const
    {
        if(pwr==BS.pwr)
        {
            return tp<BS.tp;
        }
        return pwr<BS.pwr;
    }
};
vector<BaseShip> t;
void javit(BaseShip & BS)
{
    for(int i=1; i<=n; i++)
    {
        if(tav[i][BS.lo]>=0)
        {
            legjobb[i][tav[i][BS.lo]]=max(legjobb[i][tav[i][BS.lo]], (long long)BS.cost);
        }
    }
}
long long ertek(BaseShip & BS)
{
    //cout<<BS.idx<<" start:"<<endl;
    long long ret=-infi;
    //cout<<"ret: "<<ret<<endl;
    for(int dd=0; dd<=min(n-1, BS.fuel); dd++)
    {
        //cout<<"legjobb "<<BS.lo<<" "<<dd<<" = "<<(long long)legjobb[BS.lo][dd]<<endl;
        ret=max(ret, (long long)legjobb[BS.lo][dd]);
        //cout<<"ret: "<<ret<<endl;
    }
    return ret;
}
vector<int> G[100009];
vector<long long> cap[100009];
vector<long long> flow[100009];
vector<int> holvan[100009];
int bejar[100009];
int bejarszam;
int apa[100009];
int apael[100009];
long long profitsum=0;
int sor[100009];
long long FF()
{
    long long ret=0;
    int start=0;
    int sk;
    int sv;
    while(1)
    {
        sk=1;
        sv=1;
        sor[1]=start;
        bejarszam++;
        bejar[start]=bejarszam;
        apa[start]=-1;
        apael[start]=-1;
        while(sk<=sv)
        {
            int akt=sor[sk];
            for(int i=0; i<G[akt].size(); i++)
            {
                int sz=G[akt][i];
                long long cc=cap[akt][i];
                if(bejar[sz]==bejarszam) continue;
                if(cc==flow[akt][i]) continue;
                sv++;
                sor[sv]=sz;
                apa[sz]=akt;
                apael[sz]=i;
                bejar[sz]=bejarszam;
            }
            sk++;
        }
        if(bejar[s+1]<bejarszam) break;
        long long maxpush=infi;
        int akt=s+1;
        while(akt!=0)
        {
            if(cap[apa[akt]][apael[akt]]==0)
            {
                maxpush=min(maxpush, flow[apa[akt]][apael[akt]]);
            }
            else
            {
                maxpush=min(maxpush, cap[apa[akt]][apael[akt]]-flow[apa[akt]][apael[akt]]);
            }
            //cout<<akt<<"->";
            akt=apa[akt];
        }
        //cout<<endl;
        akt=s+1;
        while(akt!=0)
        {
            //at kell irni a folyamot
            if(cap[apa[akt]][apael[akt]]==0)
            {
                flow[apa[akt]][apael[akt]]-=maxpush;
                flow[akt][holvan[apa[akt]][apael[akt]]]-=maxpush;
            }
            else
            {
                flow[apa[akt]][apael[akt]]+=maxpush;
                flow[akt][holvan[apa[akt]][apael[akt]]]+=maxpush;
            }
            akt=apa[akt];
        }
        ret+=maxpush;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            tav[i][j]=-1;
        }
        tav[i][i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a!=b)
        {
            tav[a][b]=1;
            tav[b][a]=1;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(tav[i][k]>=0 && tav[k][j]>=0)
                {
                    if(tav[i][j]==-1 || tav[i][j]>tav[i][k]+tav[k][j]) tav[i][j]=tav[i][k]+tav[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            legjobb[i][j]=-infi;
        }
    }
    cin>>s>>b>>KK;
    t.resize(s+b);
    for(int i=0; i<s; i++)
    {
        cin>>t[i].lo>>t[i].pwr>>t[i].fuel>>t[i].cost;
        t[i].tp=1;
        t[i].idx=i+1;
    }
    for(int i=s; i<s+b; i++)
    {
        cin>>t[i].lo>>t[i].pwr>>t[i].cost;
        t[i].tp=0;
    }
    sort(t.begin(), t.end());
    for(int i=0; i<t.size(); i++)
    {
        //cout<<"5_0: "<<legjobb[5][0]<<endl;
        if(t[i].tp==0)
        {
            javit(t[i]);
        }
        else
        {
            profit[t[i].idx]=ertek(t[i])-t[i].cost;
            //cout<<t[i].idx<<" profit: "<<profit[t[i].idx]<<endl;
            if(profit[t[i].idx]>=0)
            {
                profitsum+=profit[t[i].idx];
            }
        }
    }
    for(int i=1; i<=KK; i++)
    {
        int s1, s2;
        cin>>s1>>s2;
        if(s1==s2) continue;
        holvan[s1].push_back(G[s2].size());
        holvan[s2].push_back(G[s1].size());
        G[s1].push_back(s2);
        G[s2].push_back(s1);
        cap[s1].push_back(infi);
        cap[s2].push_back(0);
        flow[s1].push_back(0);
        flow[s2].push_back(0);
    }
    for(int i=1; i<=s; i++)
    {
        if(G[i].size()==0) continue;
        if(profit[i]>=0)
        {
            holvan[0].push_back(G[i].size());
            holvan[i].push_back(G[0].size());
            G[0].push_back(i);
            G[i].push_back(0);
            cap[0].push_back(profit[i]);
            cap[i].push_back(0);
            flow[0].push_back(0);
            flow[i].push_back(0);
        }
        else
        {
            holvan[s+1].push_back(G[i].size());
            holvan[i].push_back(G[s+1].size());
            G[s+1].push_back(i);
            G[i].push_back(s+1);
            cap[s+1].push_back(0);
            cap[i].push_back(-profit[i]);
            flow[s+1].push_back(0);
            flow[i].push_back(0);
        }
    }
    /*for(int i=1; i<=s; i++)
    {
        cout<<profit[i]<<" --profit"<<endl;
    }
    for(int i=0; i<=s+1; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
            int sz=G[i][j];
            cout<<i<<" --- "<<sz<<" cap: "<<cap[i][j]<<" folyam: "<<flow[i][j]<<endl;
        }
    }*/
    long long mincut=FF();
    //cout<<"mincut: "<<mincut<<endl;
    cout<<profitsum-mincut<<endl;
    return 0;
}