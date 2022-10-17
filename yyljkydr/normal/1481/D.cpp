#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7,M=1e5+1e3+7;

int T,n,m,ans[M];

char s[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        int x=-1,y=-1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(s[i][j]==s[j][i])
                    x=i,y=j;
        if(x!=-1)
        {
            for(int i=1;i<=m+1;i++)
                ans[i]=i&1?x:y;
            puts("YES");
            for(int i=1;i<=m+1;i++)
                printf("%d%c",ans[i]," \n"[i==m+1]);
        }
        else
        {
            if(m&1)
            {
                puts("YES");
                for(int i=1;i<=m+1;i++)
                    printf("%d%c",(i&1)+1," \n"[i==m+1]);
            }
            else
            {
                int ok=0;
                for(int i=1;i<=n;i++)
                {
                    int x=-1,y=-1;
                    for(int j=1;j<=n;j++)
                        if(s[i][j]=='a')
                            x=j;
                        else if(s[i][j]=='b')
                            y=j;
                    if(x!=-1&&y!=-1)
                    {
                        ok=1;
                        if(m/2%2==0)
                        {
                            for(int j=1;j<=m/2;j++)
                                ans[j]=j&1?i:x;
                            ans[m/2+1]=i;
                            for(int j=1;j<=m/2;j++)
                                ans[j+m/2+1]=j&1?y:i;
                        }
                        else
                        {
                            for(int j=1;j<=m/2;j++)
                                ans[j]=j&1?x:i;
                            ans[m/2+1]=i;
                            for(int j=1;j<=m/2;j++)
                                ans[j+m/2+1]=j&1?y:i;
                        }
                        puts("YES");
                        for(int i=1;i<=m+1;i++)
                           printf("%d%c",ans[i]," \n"[i==m+1]);
                        break;
                    }
                }
                if(!ok)
                    puts("NO");
            }
        }
    }
}