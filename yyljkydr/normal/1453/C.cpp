#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,a[N][N],ans[N],T;

char s[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=s[i][j]-'0';
        for(int k=0;k<10;k++)
            ans[k]=0;
        for(int k=0;k<10;k++)
        {
            int up=1e9,dw=-1;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(a[i][j]==k)
                        up=min(up,i),dw=max(dw,i);
            if(dw==-1)
                continue;
            for(int i=1;i<=n;i++)
            {
                int mn=1e9,mx=-1;
                for(int j=1;j<=n;j++)
                    if(a[i][j]==k)
                    {
                        mn=min(mn,j);
                        mx=max(mx,j);
                    }
                if(mx==-1)
                    continue;
                ans[k]=max(ans[k],(mx-mn)*max(i-1,n-i));
                ans[k]=max(ans[k],(n-mn)*max(i-up,dw-i));
                ans[k]=max(ans[k],(mx-1)*max(i-up,dw-i));
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                swap(a[i][j],a[j][i]);
        for(int k=0;k<10;k++)
        {
            int up=1e9,dw=-1;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(a[i][j]==k)
                        up=min(up,i),dw=max(dw,i);
            if(dw==-1)
                continue;
            for(int i=1;i<=n;i++)
            {
                int mn=1e9,mx=-1;
                for(int j=1;j<=n;j++)
                    if(a[i][j]==k)
                    {
                        mn=min(mn,j);
                        mx=max(mx,j);
                    }
                if(mx==-1)
                    continue;
                ans[k]=max(ans[k],(mx-mn)*max(i-1,n-i));
                ans[k]=max(ans[k],(n-mn)*max(i-up,dw-i));
                ans[k]=max(ans[k],(mx-1)*max(i-up,dw-i));
            }
        }
        for(int i=0;i<10;i++)
            printf("%d ",ans[i]);
        puts("");
    }
}