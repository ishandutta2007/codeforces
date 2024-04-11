#include <iostream>
using namespace std;
int n, m, q;
int er[509][509];
int sor[509];
int main()
{
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>er[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int aktu=0;
        sor[i]=0;
        for(int j=1; j<=m; j++)
        {
            if(er[i][j]==1)
            {
                aktu++;
                if(j==m)
                {
                    sor[i]=max(sor[i], aktu);
                }
            }
            else
            {
                sor[i]=max(sor[i], aktu);
                aktu=0;
            }
        }
        //cout<<sor[i]<<endl<<endl;
    }
    for(int t=1; t<=q; t++)
    {
        int a, b;
        cin>>a>>b;
        if(er[a][b]==1)
        {
            er[a][b]=0;
        }
        else
        {
            er[a][b]=1;
        }
        int aktu=0;
        sor[a]=0;
        for(int j=1; j<=m; j++)
        {
            if(er[a][j]==1)
            {
                aktu++;
                if(j==m)
                {
                    sor[a]=max(sor[a], aktu);
                }
            }
            else
            {
                sor[a]=max(sor[a], aktu);
                aktu=0;
            }
        }
        int maxi=sor[1];
        for(int u=2; u<=n; u++)
        {
            if(sor[u]>maxi)
            {
                maxi=sor[u];
            }
        }
        cout<<maxi<<endl;
    }

    return 0;
}