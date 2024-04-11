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
        scanf("%d",&n);
        scanf("%s",s+1);
        int len=strlen(s+1);
        int cr=0,cd=0;
        for(int i=1;i<=len;i++)
            cr+=s[i]=='R',cd+=s[i]=='D';
        if(!cr||!cd)
        {
            printf("%d\n",n);
            continue;
        }
        int r=n-cr-1,d=n-cd-1;
        int x=cr+1,y=cd+1;
        long long ans=1ll*min(r+1,n-x+1)*min(d+1,n-y+1);
        int pos=1;
        while(pos+1<=len&&s[pos+1]==s[1])
            pos++;
        for(int i=len;i>pos;i--)
        {
            if(s[i]=='R')
            {
                x--;
                ans+=min(d+1,n-y+1);
            }
            else
            {
                y--;
                ans+=min(r+1,n-x+1);
            }
        }
        ans+=pos;
        printf("%lld\n",ans);
    }
}