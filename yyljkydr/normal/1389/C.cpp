#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=n-2;
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
                int x=i,tot=0;
                for(int t=1;t<=n;t++)
                {
                    if(s[t]-'0'!=x)
                        tot++;
                    else
                        x=x^i^j;
                }
                if(x==j&&i!=j)
                    tot++;
                ans=min(ans,tot);
            }
        printf("%d\n",ans);
    }
}