#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m, q;
long long tabla[109][109];
long long tp[10009], xx[10009], yy[10009], val[10009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>tp[i];
        if(tp[i]==3)
        {
            cin>>xx[i]>>yy[i]>>val[i];
        }
        else
        {
            cin>>val[i];
        }
    }
    for(int u=q; u>=1; u--)
    {
        if(tp[u]==3)
        {
            tabla[xx[u]][yy[u]]=val[u];
        }
        else if(tp[u]==2)
        {
            long long utvolt=tabla[n][val[u]];
            for(int z=n; z>1; z--)
            {
                tabla[z][val[u]]=tabla[z-1][val[u]];
            }
            tabla[1][val[u]]=utvolt;
        }
        else if(tp[u]==1)
        {
            long long utvolt=tabla[val[u]][m];
            for(int z=m; z>1; z--)
            {
                tabla[val[u]][z]=tabla[val[u]][z-1];
            }
            tabla[val[u]][1]=utvolt;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<tabla[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}