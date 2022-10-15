#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=305;
int T;
int n,k;
int gr[maxn][maxn];
int numo[3],numx[3];
int main()
{
    T=read();
    while(T--)
    {
        n=read();k=0;
        numo[0]=numo[1]=numo[2]=0;
        numx[0]=numx[1]=numx[2]=0;
        for(int i=1;i<=n;i++)
        {
            char s[maxn];scanf("%s",s+1);
            for(int j=1;j<=n;j++)
            {
                if(s[j]=='X')gr[i][j]=1;
                else if(s[j]=='O')gr[i][j]=2;
                else gr[i][j]=0;
                if(gr[i][j]==1)numx[(i+j)%3]++,k++;
                else if(gr[i][j]==2)numo[(i+j)%3]++,k++;
            }
        }
        if(numx[0]+numo[1]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==0)gr[i][j]=2;
                        else if((i+j)%3==1)gr[i][j]=1;
                    }
                }
        }
        else if(numo[0]+numx[1]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==0)gr[i][j]=1;
                        else if((i+j)%3==1)gr[i][j]=2;
                    }
                }
        }
        else if(numx[0]+numo[2]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==0)gr[i][j]=2;
                        else if((i+j)%3==2)gr[i][j]=1;
                    }
                }
        }
        else if(numo[0]+numx[2]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==0)gr[i][j]=1;
                        else if((i+j)%3==2)gr[i][j]=2;
                    }
                }
        }
        else if(numx[1]+numo[2]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==1)gr[i][j]=2;
                        else if((i+j)%3==2)gr[i][j]=1;
                    }
                }
        }
        else if(numo[1]+numx[2]<=k/3)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(gr[i][j])
                    {
                        if((i+j)%3==1)gr[i][j]=1;
                        else if((i+j)%3==2)gr[i][j]=2;
                    }
                }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(gr[i][j]==0)printf(".");
                else if(gr[i][j]==1)printf("X");
                else if(gr[i][j]==2)printf("O");
            }
            printf("\n");
        }
    }
}