#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,m,k;

int c[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n%2==0&&m%2==0)
        {
            puts(k%2==0?"YES":"NO");
            if(k%2==0)
            {
                int tt=0;
                for(int i=1;i<=n;i+=2)
                {
                    int t=(tt^=2);
                    for(int j=1;j<=m;j+=2)
                    {
                        if(k)
                        {
                            k-=2;
                            c[i][j]=c[i][j+1]=(t++)%4;
                            c[i+1][j]=c[i+1][j+1]=(t++)%4;
                        }
                        else
                        {
                            c[i][j]=c[i+1][j]=(t++)%4;
                            c[i][j+1]=c[i+1][j+1]=(t++)%4;
                        }
                    }
                }
                for(int i=1;i<=n;i++,puts(""))
                    for(int j=1;j<=m;j++)
                        putchar(c[i][j]+'a');
            }
        }
        else
        {
            int swp=0;
            if(m%2==1)
                swap(n,m),k=n*m/2-k,swp=1;
            if(k<m/2)
                puts("NO");
            else if((k-m/2)%2!=0)
                puts("NO");
            else
            {
                puts("YES");
                int tt=0;
                for(int i=1;i+1<=n;i+=2)
                {
                    int t=(tt^=2);
                    for(int j=1;j<=m;j+=2)
                    {
                        if(k>m/2)
                        {
                            k-=2;
                            c[i][j]=c[i][j+1]=(t++)%4;
                            c[i+1][j]=c[i+1][j+1]=(t++)%4;
                        }
                        else
                        {
                            c[i][j]=c[i+1][j]=(t++)%4;
                            c[i][j+1]=c[i+1][j+1]=(t++)%4;
                        }
                    }
                }
                int t=(tt^=2);
                for(int j=1;j<=m;j+=2)
                {
                    c[n][j]=c[n][j+1]=t%4;
                    t+=2;
                }
                if(!swp)
                {
                    for(int i=1;i<=n;i++,puts(""))
                        for(int j=1;j<=m;j++)
                            putchar(c[i][j]+'a');
                }
                else
                {
                    for(int i=1;i<=m;i++,puts(""))
                        for(int j=1;j<=n;j++)
                            putchar(c[j][i]+'a');
                }
            }
        }
    }
}