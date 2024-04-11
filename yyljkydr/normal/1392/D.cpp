#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

char s[N];

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int bg=1;
        while(s[bg]==s[n]&&bg<=n)
            bg++;
        if(bg==n+1)
            printf("%d\n",(n-1)/3+1);
        else
        {
            int ans=0,cnt=0,flag=0;
            for(int i=bg;!flag||i!=bg;i=(i==n)?1:i+1)
            {
                flag=1;
                cnt++;
                if(s[i]!=s[(i==n)?1:i+1])
                    ans+=cnt/3,cnt=0;
            }
            ans+=cnt/3;
            printf("%d\n",ans);
        }
    }
}