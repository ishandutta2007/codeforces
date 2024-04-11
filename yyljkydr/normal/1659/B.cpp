#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,k;

char s[N];

int ans[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
            ans[i]=0;
        int tar=0,flp=0;
        if(k&1)
            k--,tar^=1,flp=1;
        int la=-1;
        for(int i=1;i<=n;i++)
        {
            if(!k)
                break;
            if(s[i]-'0'!=tar)
                continue;
            if(la==-1)
                la=i;
            else
            {
                s[la]=s[i]=(tar^1)+'0';
                ans[la]++,ans[i]++;
                k-=2;
                la=-1;
            }
        }
        if(k)
        {
            for(int i=1;i<n;i++)
                if(s[i]-'0'==tar)
                {
                    s[i]=(tar^1)+'0',s[n]=tar+'0';
                    ans[i]++,ans[n]++;
                    k-=2;
                    break;
                }
        }
        if(flp)
        {
            for(int i=1;i<=n;i++)
                if(s[i]-'0'==1||i==n)
                {
                    for(int j=1;j<=n;j++)
                        if(j!=i)
                            s[j]=((s[j]-'0')^1)+'0';
                    ans[i]++;
                    break;
                }
        }
        if(k)
            ans[n]+=k;
        puts(s+1);
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i]," \n"[i==n]);
    }
}