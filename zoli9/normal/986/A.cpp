#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int szin[100009];
int bejar[100009];
int bsz=0;
vector<int> G[100009];
vector<int> kik[109];
int sk, sv;
int sor[200009];
vector<int> szint[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>szin[i];
        kik[szin[i]].push_back(i);
        szint[i].resize(k);
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int col=1; col<=k; col++)
    {
        sk=1;
        sv=0;
        bsz++;
        for(int i=0; i<kik[col].size(); i++)
        {
            int varos=kik[col][i];
            bejar[varos]=bsz;
            szint[varos][col-1]=0;
            sv++;
            sor[sv]=varos;
        }
        while(sk<=sv)
        {
            int akt=sor[sk];
            for(int sz: G[akt])
            {
                if(bejar[sz]<bsz)
                {
                    bejar[sz]=bsz;
                    szint[sz][col-1]=szint[akt][col-1]+1;
                    sv++;
                    sor[sv]=sz;
                }
            }
            sk++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        int szum=0;
        sort(szint[i].begin(), szint[i].end());
        for(int j=0; j<s; j++)
        {
            szum+=szint[i][j];
        }
        cout<<szum<<" ";
    }
    cout<<endl;
    return 0;
}