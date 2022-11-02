#include <iostream>
using namespace std;
int n, m, b, mod;
int ai[501];
int d[2][501][501];
int main()
{
    cin>>n>>m>>b>>mod;
    for(int i=1; i<=n; i++)
    {
        cin>>ai[i];
    }
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=b; j++)
        {
            d[0][i][j]=0;
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=b; j++)
        {
            d[i%2][0][j]=1;
        }
    }
    for(int nnn=n; nnn>=1; nnn--)
    {
        for(int mmm=1; mmm<=m; mmm++)
        {
            for(int bbb=0; bbb<=b; bbb++)
            {
                d[nnn%2][mmm][bbb]=0;
                int bx=bbb;
                bx-=ai[nnn];
                if(bx>=0)
                {
                    d[nnn%2][mmm][bbb]+=d[nnn%2][mmm-1][bx];
                }
                if(nnn<n)
                {

                        d[nnn%2][mmm][bbb]+=d[(nnn+1)%2][mmm][bbb];

                }
                d[nnn%2][mmm][bbb]%=mod;
            }
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<d[i][j][b]<<" ";
        }
        cout<<endl;
    }*/
    cout<<d[1][m][b];
    return 0;
}