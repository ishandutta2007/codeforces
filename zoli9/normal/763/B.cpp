#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n;
vector<pair<pair<long long, long long>, pair<long long, long long> > > fugp;
vector<pair<pair<long long, long long>, pair<long long, long long> > > vip;
vector<int> G1[500009];
vector<int> G2[500009];
bool bejar1[500009];
bool bejar2[500009];
int szin1[500009];
int szin2[500009];
void dfs1(int x)
{
    bejar1[x]=true;
    for(int sz: G1[x])
    {
        if(!bejar1[sz])
        {
            szin1[sz]=1-szin1[x];
            dfs1(sz);
        }
    }
}
void dfs2(int x)
{
    bejar2[x]=true;
    for(int sz: G2[x])
    {
        if(!bejar2[sz])
        {
            szin2[sz]=1-szin2[x];
            dfs2(sz);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long A, B, C, D;
        cin>>A>>B>>C>>D;
        fugp.push_back(make_pair(make_pair(B, A), make_pair(1, i)));
        fugp.push_back(make_pair(make_pair(B, C), make_pair(0, i)));
        fugp.push_back(make_pair(make_pair(D, A), make_pair(1, i)));
        fugp.push_back(make_pair(make_pair(D, C), make_pair(0, i)));

        vip.push_back(make_pair(make_pair(A, B), make_pair(1, i)));
        vip.push_back(make_pair(make_pair(A, D), make_pair(0, i)));
        vip.push_back(make_pair(make_pair(C, B), make_pair(1, i)));
        vip.push_back(make_pair(make_pair(C, D), make_pair(0, i)));
    }
    sort(fugp.begin(), fugp.end());
    vector<int> bent;
    for(int i=0; i<fugp.size(); i++)
    {
        pair<pair<long long, long long>, pair<long long, long long> > akt=fugp[i];
        if(i==0 || akt.F.F!=fugp[i-1].F.F)
        {
            bent.clear();
        }
        if(akt.S.F==1)
        {
            for(int u=0; u<bent.size(); u++)
            {
                G1[bent[u]].push_back(akt.S.S);
                G1[akt.S.S].push_back(bent[u]);
                //cout<<"uj el: "<<bent[u]<<" "<<akt.S.S<<endl;
            }
            bent.push_back(akt.S.S);
        }
        else
        {
            if(bent[1]==akt.S.S) bent.pop_back();
            else
            {
                bent[0]=bent[1];
                bent.pop_back();
            }
        }
    }


    sort(vip.begin(), vip.end());
    bent.clear();
    for(int i=0; i<vip.size(); i++)
    {
        pair<pair<long long, long long>, pair<long long, long long> > akt=vip[i];
        if(i==0 || akt.F.F!=vip[i-1].F.F)
        {
            bent.clear();
        }
        if(akt.S.F==1)
        {
            for(int u=0; u<bent.size(); u++)
            {
                G2[bent[u]].push_back(akt.S.S);
                G2[akt.S.S].push_back(bent[u]);
                //cout<<"uj el: "<<bent[u]<<" "<<akt.S.S<<endl;
            }
            bent.push_back(akt.S.S);
        }
        else
        {
            if(bent[1]==akt.S.S) bent.pop_back();
            else
            {
                bent[0]=bent[1];
                bent.pop_back();
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar1[i])
        {
            szin1[i]=0;
            dfs1(i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar2[i])
        {
            szin2[i]=0;
            dfs2(i);
        }
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<szin1[i]+2*szin2[i]+1<<endl;
    }
    return 0;
}