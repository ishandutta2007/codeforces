#include<bits/stdc++.h>
using namespace std;

int n;

int h[11][11];

int to[111];

double f[111];

int main()
{
    int n=10;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i%2==0)
            {
                int x;
                scanf("%d",&x);
                int t=(i-x);
                if(t%2==0)
                    to[(n-i+1-1)*n+j]=(n-i+1-1+x)*n+j;
                else
                    to[(n-i+1-1)*n+j]=(n-i+1-1+x)*n+n-j+1;

            }
            else
            {
                int x;
                scanf("%d",&x);
                int t=(i-x);
                if(t%2==0)
                    to[(n-i+1-1)*n+n-j+1]=(n-i+1-1+x)*n+j;
                else
                    to[(n-i+1-1)*n+n-j+1]=(n-i+1-1+x)*n+n-j+1;
            }
        }
    f[100]=0;
    for(int i=1;i<6;i++)
    {
        //f[100 - i] = 1 + f[100 - i] * (6 - i) / 6 + f[...]
        double s=0;
        for(int j=100-i+1;j<=100;j++)
            s+=f[j];
        f[100-i]=s/i+6.0/i;
    }
    for(int i=100-6;i>=1;i--)
    {
        double s=0;
        for(int j=i+1;j<=i+6;j++)
        {
            if(to[j]==j)
                s+=f[j];
            else
                s+=min(f[j],f[to[j]]);
        }
        f[i]=s/6+1;
    }
    printf("%.15lf\n",f[1]);
}