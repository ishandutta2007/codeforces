#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
vector<int> G[200009];
vector<int> voltel[200009]; //0 semmi 1 bejart 2 fa
vector<int> hanyadikm[200009];
int apa[200009];
int melyseg[200009];
bool bejar[200009];
int maradtszom[200009];
vector<pair<pair<int, int>, int> > answer;
set<pair<pair<int, int>, pair<int, int> > > S; //melyseg, apa, vanmszom, level
int gyszam[200009];
bool fael(int x, int y)
{
    if(apa[x]==y || apa[y]==x) return true;
    return false;
}
void dfs(int x)
{
    bejar[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        int sz=G[x][i];
        if(!bejar[sz])
        {
            apa[sz]=x;
            gyszam[x]++;
            voltel[x][i]=2;
            voltel[sz][hanyadikm[x][i]]=2;
            melyseg[sz]=melyseg[x]-1;
            dfs(sz);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        voltel[a].push_back(false);
        voltel[b].push_back(false);
        hanyadikm[a].push_back(G[b].size()-1);
        hanyadikm[b].push_back(G[a].size()-1);
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            melyseg[i]=-1;
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        int joindex=-1;
        for(int j=0; j<G[i].size(); j++)
        {
            if(voltel[i][j]==0)
            {
                if(joindex==-1)
                {
                    joindex=j;
                }
                else
                {
                    int sz1=G[i][joindex];
                    int sz2=G[i][j];
                    voltel[i][joindex]=1;
                    voltel[i][j]=1;
                    voltel[sz1][hanyadikm[i][joindex]]=1;
                    voltel[sz2][hanyadikm[i][j]]=1;
                    answer.push_back({{sz1, i}, sz2});
                    joindex=-1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
            if(voltel[i][j]==0)
            {
               maradtszom[i]=G[i][j];
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(apa[i]==0) continue;
        if(gyszam[i]!=0) continue;
        pair<pair<int, int>, pair<int, int> > aq;
        aq.F.F=melyseg[i];
        aq.F.S=apa[i];
        aq.S.F=-maradtszom[i];
        aq.S.S=i;
        S.insert(aq);
    }
    while(S.size()>0)
    {
        pair<pair<int, int>, pair<int, int> > lev=*S.begin();
        int lcs=lev.S.S;
        int acs=lev.F.S;
        int melycs=lev.F.F;
        S.erase(S.begin());
        gyszam[acs]--;
        if(maradtszom[lcs]>0)
        {
            answer.push_back({{acs, lcs}, maradtszom[lcs]});
            int malcs=maradtszom[lcs];
            maradtszom[malcs]=0;
            maradtszom[lcs]=0;

            if(gyszam[acs]==0)
            {
                //cout<<"siker";
                pair<pair<int, int>, pair<int, int> > aq;
                aq.F.F=melyseg[acs];
                aq.F.S=apa[acs];
                aq.S.F=-maradtszom[acs];
                aq.S.S=acs;
                S.insert(aq);
            }

            continue;
        }
        if(gyszam[acs]>0)
        {
            lev=*S.begin();
            int lcs2=lev.S.S;
            int acs2=lev.F.S;
            int melycs2=lev.F.F;
            S.erase(S.begin());
            gyszam[acs]--;
            answer.push_back({{lcs, acs}, lcs2});
            if(gyszam[acs]==0)
            {
                pair<pair<int, int>, pair<int, int> > aq;
                aq.F.F=melyseg[acs];
                aq.F.S=apa[acs];
                aq.S.F=-maradtszom[acs];
                aq.S.S=acs;
                S.insert(aq);
            }
            continue;
        }
        if(maradtszom[acs]>0)
        {
            answer.push_back({{lcs, acs}, maradtszom[acs]});
            int malcs=maradtszom[acs];
            maradtszom[malcs]=0;
            maradtszom[acs]=0;

            pair<pair<int, int>, pair<int, int> > aq;
            aq.F.F=melyseg[acs];
            aq.F.S=apa[acs];
            aq.S.F=-maradtszom[acs];
            aq.S.S=acs;
            S.insert(aq);

            continue;
        }
        if(apa[acs]!=0)
        {
            answer.push_back({{lcs, acs}, apa[acs]});
            gyszam[apa[acs]]--;
            if(gyszam[apa[acs]]==0)
            {
                pair<pair<int, int>, pair<int, int> > aq;
                int acsa=apa[acs];
                aq.F.F=melyseg[acsa];
                aq.F.S=apa[acsa];
                aq.S.F=-maradtszom[acsa];
                aq.S.S=acsa;
                S.insert(aq);
            }
        }
    }

    /*for(int i=1; i<=n; i++)
    {
        cout<<"apa "<<i<<" "<<apa[i]<<endl;
    }*/

    cout<<answer.size()<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i].F.F<<" "<<answer[i].F.S<<" "<<answer[i].S<<endl;
    }

    return 0;
}