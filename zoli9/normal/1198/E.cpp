#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int x1[59];
int y1[59];
int x2[59];
int y2[59];
int infi=1e9+7;
set<int> xkor, ykor;
unordered_map<int, int> getx, gety;
vector<int> distx, disty;
int cap[2009][2009];
int flow[2009][2009];
int sor[2009];
int bejar[2009];
int bejarszam=0;
int apa[2009];
int MaxFlow(int sinknode)
{
    int maxflow=0;
    while(1)
    {
        int sk=1;
        int sv=1;
        sor[1]=0;
        bejarszam++;
        bejar[0]=bejarszam;
        apa[0]=0;
        while(sk<=sv)
        {
            int akt=sor[sk];
            for(int sz=0; sz<=sinknode; sz++)
            {
                if(bejar[sz]==bejarszam) continue;
                if(flow[akt][sz]<cap[akt][sz] || flow[sz][akt]>0)
                {
                    sv++;
                    sor[sv]=sz;
                    apa[sz]=akt;
                    bejar[sz]=bejarszam;
                }
            }
            sk++;
        }
        if(bejar[sinknode]<bejarszam) break;
        int akt=sinknode;
        int plusz=infi;
        while(akt!=0)
        {
            int a=apa[akt];
            if(flow[a][akt]<cap[a][akt])
            {
                plusz=min(plusz, cap[a][akt]-flow[a][akt]);
            }
            else
            {
                plusz=min(plusz, flow[akt][a]);
            }
            akt=a;
        }
        akt=sinknode;
        maxflow+=plusz;
        while(akt!=0)
        {
            int a=apa[akt];
            if(cap[a][akt]-flow[a][akt]>=plusz)
            {
                flow[a][akt]+=plusz;
            }
            else
            {
                flow[akt][a]-=plusz;
            }
            akt=a;
        }
    }
    return maxflow;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        xkor.insert(x1[i]);
        xkor.insert(x2[i]+1);
        ykor.insert(y1[i]);
        ykor.insert(y2[i]+1);
    }
    int xcnt=0;
    int lastx=0;
    for(int xx: xkor)
    {
        getx[xx]=xcnt;
        xcnt++;
        if(lastx>0)
        {
            distx.push_back(xx-lastx);
            cap[0][distx.size()]=distx.back();
        }
        lastx=xx;
    }
    int ycnt=0;
    int lasty=0;
    for(int yy: ykor)
    {
        gety[yy]=ycnt;
        ycnt++;
        if(lasty>0)
        {
            disty.push_back(yy-lasty);
        }
        lasty=yy;
    }
    int sinknode=distx.size()+disty.size()+1;
    for(int i=0; i<disty.size(); i++)
    {
        cap[distx.size()+i+1][sinknode]=disty[i];
    }
    for(int i=1; i<=m; i++)
    {
        int xa=getx[x1[i]];
        int xb=getx[x2[i]+1];
        int ya=gety[y1[i]];
        int yb=gety[y2[i]+1];
        for(int j1=xa; j1<xb; j1++)
        {
            for(int j2=ya; j2<yb; j2++)
            {
                cap[j1+1][distx.size()+j2+1]=infi;
            }
        }
    }
    cout<<MaxFlow(sinknode)<<endl;




    return 0;
}