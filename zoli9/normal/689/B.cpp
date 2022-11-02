#include <bits/stdc++.h>
using namespace std;
int n;
int a[200009];
int sor[200009];
int szint[200009];
int sk, sv;
vector<int> G[200009];
bool bejar[200009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        G[i].push_back(a[i]);
        if(i<n)
        {
            G[i].push_back(i+1);
            G[i+1].push_back(i);
        }
    }
    sor[1]=1;
    sk=1;
    sv=1;
    szint[1]=0;
    bejar[1]=true;
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
            }
        }
        sk++;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<szint[i]<<" ";
    }
    cout<<endl;
    return 0;
}