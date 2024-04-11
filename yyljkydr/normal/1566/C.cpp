#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

char s[2][N];

int f[N],las[2],n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<2;i++)
            scanf("%s",s[i]+1);
        las[0]=las[1]=-1;
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1];
            if(s[0][i]=='0'||s[1][i]=='0')
                las[0]=i;
            if(s[0][i]=='1'||s[1][i]=='1')
                las[1]=i;
            if(las[0]==-1)
                continue;
            f[i]=max(f[i],f[las[0]-1]+1);
            if(las[1]==-1)
                continue;
            f[i]=max(f[i],f[min(las[0],las[1])-1]+2);
        }
        printf("%d\n",f[n]);
    }
}