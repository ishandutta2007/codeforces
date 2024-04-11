#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
vector<pair<int, pair<int, int> > > elek;
vector<pair<int, pair<int, int> > > tobeadded;
int dad[100009];
int mag[100009];
vector<int> G[100009];
vector<int> suly[100009];
int e1[1000009];
int e2[1000009];
int apa[100009][20];
int maxi[100009][20];
int mini[100009][20];
bool bejar[100009];
int szint[100009];
int maxlog=19;
multiset<int> lehetoseg;
void dfs(int x)
{
    bejar[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        int sz=G[x][i];
        if(!bejar[sz])
        {
            apa[sz][0]=x;
            maxi[sz][0]=suly[x][i];
            szint[sz]=szint[x]+1;
            dfs(sz);
        }
    }
}
int lca(int x, int y)
{
    if(szint[x]<szint[y]) swap(x, y);
    for(int i=maxlog-1; i>=0; i--)
    {
        if(szint[x]-(1<<i)>=szint[y]) x=apa[x][i];
    }
    if(x==y) return x;
    for(int i=maxlog-1; i>=0; i--)
    {
        if(apa[x][i]!=apa[y][i])
        {
            x=apa[x][i];
            y=apa[y][i];
        }
    }
    return apa[x][0];
}

int kerd(int x, int osapa)
{
    int answer=0;
    for(int i=maxlog-1; i>=0; i--)
    {
        if(szint[apa[x][i]]>=szint[osapa])
        {
            answer=max(answer, maxi[x][i]);
            x=apa[x][i];
        }
    }
    return answer;
}
int kerdez(int x, int y)
{
    int father=lca(x, y);
    return max(kerd(x, father), kerd(y, father));
}
void unio(int x, int y)
{
    if(mag[x]<mag[y]) dad[x]=y;
    else if(mag[x]>mag[y]) dad[y]=x;
    else
    {
        mag[x]++;
        dad[y]=x;
    }
}
int holvan(int x)
{
    if(dad[x]==-1) return x;
    return dad[x]=holvan(dad[x]);
}
void modositas(int x, int osapa, int ww)
{
    for(int i=maxlog-1; i>=0; i--)
    {
        if(szint[apa[x][i]]>=szint[osapa])
        {
            mini[x][i]=min(mini[x][i], ww);
            x=apa[x][i];
        }
    }
}
void osszegez()
{
    for(int k=maxlog-1; k>0; k--)
    {
        for(int i=1; i<=n; i++)
        {
            mini[i][k-1]=min(mini[i][k-1], mini[i][k]);
            mini[apa[i][k-1]][k-1]=min(mini[apa[i][k-1]][k-1], mini[i][k]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        dad[i]=-1;
        mag[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        int a1, a2, a3;
        cin>>a1>>a2>>a3;
        e1[i]=a1;
        e2[i]=a2;
        elek.push_back({a3, {a1, a2}});
    }
    sort(elek.begin(), elek.end());
    for(int i=0; i<m; i++)
    {
        int h1=holvan(elek[i].S.F);
        int h2=holvan(elek[i].S.S);
        if(h1!=h2)
        {
            unio(h1, h2);
            //cout<<"osszekot: "<<elek[i].S.F<<" "<<elek[i].S.S<<endl;
            G[elek[i].S.F].push_back(elek[i].S.S);
            G[elek[i].S.S].push_back(elek[i].S.F);
            suly[elek[i].S.F].push_back(elek[i].F);
            suly[elek[i].S.S].push_back(elek[i].F);

        }
        else
        {
            tobeadded.push_back({elek[i]});
        }
    }
    dfs(1);
    for(int k=1; k<maxlog; k++)
    {
        for(int i=1; i<=n; i++)
        {
            apa[i][k]=apa[apa[i][k-1]][k-1];
            maxi[i][k]=max(maxi[i][k-1], maxi[apa[i][k-1]][k-1]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int k=0; k<maxlog; k++)
        {
            mini[i][k]=1000000000;
        }
    }
    for(int i=0; i<tobeadded.size(); i++)
    {
        int lll=lca(tobeadded[i].S.F, tobeadded[i].S.S);
        modositas(tobeadded[i].S.F, lll, tobeadded[i].F);
        modositas(tobeadded[i].S.S, lll, tobeadded[i].F);
    }
    osszegez();
    for(int i=1; i<=m; i++)
    {
        if(apa[e1[i]][0]==e2[i] || apa[e2[i]][0]==e1[i])
        {
            int x=e1[i];
            int y=e2[i];
            if(apa[y][0]==x) swap(x, y);
            cout<<mini[x][0]<<endl;
        }
        //cout<<e1[i]<<" - "<<e2[i]<<endl;
        else cout<<kerdez(e1[i], e2[i])<<'\n';
    }
    return 0;
}