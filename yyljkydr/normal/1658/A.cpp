#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

char s[N];

int T;

int n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='0')
                cnt++;
        if(cnt<=1)
            puts("0");
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i]!='0')
                    continue;
                int p=-1;
                for(int j=i+1;j<=n;j++)
                    if(s[j]=='0')
                    {
                        p=j;
                        break;
                    }
                if(p!=-1)
                {
                    if(p-i-1<=2)
                        ans+=2-(p-i-1);
                }
            }
            printf("%d\n",ans);
        }
    }
}