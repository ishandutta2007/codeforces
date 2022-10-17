#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int T;

char s[N];

int w[N],x,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        scanf("%d",&x);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)
            w[i]=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='0')
            {
                if(i-x>=1)
                    w[i-x]=0;
                if(i+x<=n)
                    w[i+x]=0;
            }
        int ok=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='1')
            {
                int th=0;
                if(i-x>=1&&w[i-x])
                    th=1;
                if(i+x<=n&&w[i+x])
                    th=1;
                ok&=th;
            }
        if(!ok)
            puts("-1");
        else
        {
            for(int i=1;i<=n;i++)
                printf("%d",w[i]);
            puts("");
        }
    }
}