#include <bits/stdc++.h>
using namespace std;
int n;
long long MOD=1000000007;
int kov[200009];
vector<int> V[200009];
vector<int> G[200009];
bool bejar[200009];
int kompszam[200009];
bool kor=false;
int elido[200009];
int elhagy=0;
long long dbk[200009];
int tipus[200009]; //0: rendes 1: odav 2 kor
void dfs(int x)
{
    bejar[x]=true;

    for(int sz: V[x])
    {
        if(!bejar[sz])
        {
            dfs(sz);
        }
    }
    elhagy++;
    elido[x]=elhagy;
}
bool bej[200009];
int ido=0;
void mely(int x)
{
    kompszam[x]=ido;
    dbk[ido]++;
    bej[x]=true;
    for(int sz: G[x])
    {
        if(!bej[sz]) mely(sz);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a, b;
        cin>>a>>b;
        kov[a]=b;
        V[b].push_back(a);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=2*n; i++)
    {
        if(!bej[i])
        {
            if(G[i].size()>0)
            {


            ido++;
            mely(i);

            }
        }
    }
    for(int i=1; i<=2*n; i++)
    {
        if(!bejar[i])
        {
            if(G[i].size()>0)
            {
                elhagy++;
                dfs(i);

            }
        }
    }
    for(int i=1; i<=2*n; i++)
    {
        for(int j=0; j<V[i].size(); j++)
        {
            if(V[i][j]==i)
            {
                tipus[kompszam[i]]=1;
                continue;
            }
            if(elido[i]<elido[V[i][j]])
            {
                //cout<<"!!! "<<i<<" "<<elido[i]<<" "<<V[i][j]<<" "<<elido[V[i][j]]<<endl;
                if(tipus[kompszam[i]]!=1)
                {
                    tipus[kompszam[i]]=2;
                }
            }
        }
    }
    long long ans=1;
    for(int i=1; i<=ido; i++)
    {
        //cout<<tipus[i]<<endl;
        if(tipus[i]==0)
        {
            ans*=(dbk[i]);
            ans%=MOD;
        }
        else if(tipus[i]==2)
        {
            ans*=2;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}