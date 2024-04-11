#include<bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        char s[111];
        scanf("%s",s+1);
        int win=0;
        string ans;
        ans.resize(n);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='S')
            {
                if(a)
                    a--,win++,ans[i-1]='R';
            }
            else if(s[i]=='R')
            {
                if(b)
                    b--,win++,ans[i-1]='P';
            }
            else if(s[i]=='P')
            {
                if(c)
                    c--,win++,ans[i-1]='S';
            }
        }
        for(int i=0;i<n;i++)
            if(ans[i]==0)
            {
                if(a)
                    a--,ans[i]='R';
                else if(b)
                    b--,ans[i]='P';
                else
                    c--,ans[i]='S';
            }
        puts(win*2>=n?"YES":"NO");
        if(win*2>=n)
            cout<<ans<<"\n";
    }
}