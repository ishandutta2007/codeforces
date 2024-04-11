#include <bits/stdc++.h>
using namespace std;
int infi=1000000007;
int kap[209][209];
int n, m;
int sum1, sum2;
int sk, sv;
int sor[2009];
int apa[2009];
int szin[2009];
int bsz;
int folyam;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>kap[0][i];
        sum1+=kap[0][i];
        kap[i][i+n]=infi;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>kap[i+n][2*n+1];
        sum2+=kap[i+n][2*n+1];
    }
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        kap[a][b+n]=infi;
        kap[b][a+n]=infi;
    }
    if(sum1!=sum2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while(1)
    {
        bsz++;
        sor[1]=0;
        sk=1;
        sv=1;
        apa[0]=-1;
        bool kesz=false;
        while(sk<=sv)
        {
            int akt=sor[sk];
            for(int i=0; i<=2*n+1; i++)
            {
                if(szin[i]<bsz && kap[akt][i]>0)
                {
                    szin[i]=bsz;
                    sv++;
                    sor[sv]=i;
                    apa[i]=akt;
                    if(i==2*n+1)
                    {
                        kesz=true;
                        break;
                    }
                }
            }
            if(kesz) break;
            sk++;
        }
        if(!kesz) break;
        int akt=2*n+1;
        int mini=infi;
        while(akt!=0)
        {
            mini=min(mini, kap[apa[akt]][akt]);
            akt=apa[akt];
        }
        akt=2*n+1;
        while(akt!=0)
        {
            kap[apa[akt]][akt]-=mini;
            kap[akt][apa[akt]]+=mini;
            akt=apa[akt];
        }
        folyam+=mini;
    }
    if(folyam!=sum1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<kap[i+n][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}