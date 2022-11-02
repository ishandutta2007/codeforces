#include <bits/stdc++.h>
using namespace std;
int n, m;
bool Abeli[1009];
vector<int> G[1009];
bool hurok[1009];
int szin[1009];
int aktszin=0;
int ans=10009;
int Par[1009];
int center;
bool utnovelo(int x)
{
    if(szin[x]>aktszin) return false;
    szin[x]=aktszin+1;
    if(Abeli[x])
    {
        for(int sz: G[x])
        {
            if(sz==center || sz==center+n) continue;
            if(szin[sz]<=aktszin)
            {
                if(utnovelo(sz))
                {
                    Par[x]=sz;
                    Par[sz]=x;
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        if(Par[x]==x) return true;
        return utnovelo(Par[x]);
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++) Abeli[i]=true;
    for(int i=1; i<=m; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        if(aa==bb) hurok[aa]=true;
        G[aa].push_back(bb+n);
        G[bb+n].push_back(aa);
    }
    int mp=0;
    for(center=1; center<=n; center++)
    {
        int aktans=n-G[center].size()+n-G[center+n].size();
        if(!hurok[center]) aktans--;
        for(int i=1; i<=2*n; i++)
        {
            Par[i]=i;
        }
        int dbmaxpar=0;
        for(int i=1; i<=n; i++)
        {
            if(i==center) continue;
            if(Par[i]==i)
            {
                if(utnovelo(i))
                {
                    dbmaxpar++;
                }
                aktszin++;
            }
        }
        int otheredge=m-G[center].size()-G[center+n].size();
        if(hurok[center]) otheredge++;
        aktans+=(otheredge-dbmaxpar);
        aktans+=(n-1-dbmaxpar);
        if(aktans<=ans)
        {
            mp=dbmaxpar;
            ans=aktans;
        }
    }
    cout<<ans<<endl;
    return 0;
}