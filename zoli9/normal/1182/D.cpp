#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[100009];
int degr[100009];
int sor[100009];
bool bejar[100009];
int sk, sv;
int szint[100009];
int apa[100009];
int maxd[100009];
int numleaf;
vector<int> szintek[100009];
vector<int> usz[100009];
int paritas[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        degr[a]++;
        degr[b]++;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(degr[i]==1) numleaf++;
    }
    int start=1;
    sor[1]=start;
    bejar[start]=true;
    sk=1;
    sv=1;
    int last=start;
    while(sk<=sv)
    {
        int akt=sor[sk];
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                sv++;
                sor[sv]=sz;
                bejar[sz]=true;
                last=sz;
            }
        }
        sk++;
    }
    for(int i=1; i<=n; i++) bejar[i]=false;
    start=last;
    szint[start]=0;
    sor[1]=start;
    bejar[start]=true;
    sk=1;
    sv=1;
    last=start;
    while(sk<=sv)
    {
        int akt=sor[sk];
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                sv++;
                sor[sv]=sz;
                bejar[sz]=true;
                apa[sz]=akt;
                last=sz;
                szint[sz]=szint[akt]+1;
            }
        }
        sk++;
    }
    int h=szint[last];
    if(numleaf==2)
    {
        cout<<last<<endl;
        return 0;
    }
    for(int i=1; i<=h/2; i++)
    {
        last=apa[last];
    }
    for(int i=1; i<=n; i++) bejar[i]=false;
    start=last;
    sor[1]=start;
    bejar[start]=true;
    sk=1;
    sv=1;
    szint[start]=0;
    maxd[start]=0;
    while(sk<=sv)
    {
        int akt=sor[sk];
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                sv++;
                sor[sv]=sz;
                bejar[sz]=true;
                szint[sz]=szint[akt]+1;
                szintek[szint[sz]].push_back(sz);
                maxd[sz]=max(maxd[akt], degr[sz]);
                if(degr[sz]==1 && maxd[sz]<=2)
                {
                    paritas[szint[sz]]++;
                }
            }
        }
        sk++;
    }
    bool okk=true;
    for(int i=1; i<=n; i++)
    {
        if(szintek[i].size()>0)
        {
            for(int j=1; j<szintek[i].size(); j++)
            {
                if(degr[szintek[i][j]]!=degr[szintek[i][0]])
                {
                    okk=false;
                    break;
                }
            }
        }
    }
    if(okk)
    {
        cout<<last<<endl;
        return 0;
    }
    int utolsostart=-1;
    for(int i=1; i<=n; i++)
    {
        if(degr[i]==1 && maxd[i]<=2 && paritas[szint[i]]==1)
        {
            utolsostart=i;
            break;
        }
    }
    if(utolsostart<=0)
    {
        cout<<-1<<endl;
        return 0;
    }



    for(int i=1; i<=n; i++) bejar[i]=false;
    start=utolsostart;
    sor[1]=start;
    bejar[start]=true;
    sk=1;
    sv=1;
    szint[start]=0;
    while(sk<=sv)
    {
        int akt=sor[sk];
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                sv++;
                sor[sv]=sz;
                bejar[sz]=true;
                szint[sz]=szint[akt]+1;
                usz[szint[sz]].push_back(sz);
            }
        }
        sk++;
    }
    okk=true;
    for(int i=1; i<=n; i++)
    {
        if(usz[i].size()>0)
        {
            for(int j=1; j<usz[i].size(); j++)
            {
                if(degr[usz[i][j]]!=degr[usz[i][0]])
                {
                    okk=false;
                    break;
                }
            }
        }
    }
    if(okk)
    {
        cout<<utolsostart<<endl;
        return 0;
    }
    cout<<-1<<endl;

    return 0;
}