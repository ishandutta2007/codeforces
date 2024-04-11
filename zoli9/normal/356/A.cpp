#include <bits/stdc++.h>
using namespace std;
int apa[300009];
int mag[300009];
int kikap[300009];
int n, m;
int kovel(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=kovel(apa[x]);
}
void unio(int x)
{
    apa[x]=x+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n+1; i++)
    {
        apa[i]=i;
        //mag[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        int k, v, gy;
        cin>>k>>v>>gy;
        int akt=kovel(k);
        while(akt<=v)
        {
            //cout<<akt<<endl;
            if(akt==gy)
            {
                akt++;
                akt=kovel(akt);
                continue;
            }
            kikap[akt]=gy;
            unio(akt);
            akt=kovel(akt);
        }
    }
    for(int i=1; i<=n; i++) cout<<kikap[i]<<" ";

    return 0;
}