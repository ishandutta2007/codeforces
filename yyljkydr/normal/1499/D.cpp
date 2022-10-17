#include<bits/stdc++.h>
using namespace std;

const int N=2e7+1e3+7;

bool vis[N];

int p[N],ptot,dv[N];

void pre(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            p[++ptot]=i,dv[i]=1;
        for(int j=1;j<=ptot&&i*p[j]<=n;j++)
        {
            vis[i*p[j]]=1;
            dv[i*p[j]]=dv[i]+1;
            if(i%p[j]==0)
            {
                dv[i*p[j]]=dv[i];
                break;
            }
        }
    }
}

int T,c,d,x;

int main()
{  
    pre(2e7);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&c,&d,&x);
        long long ans=0;
        for(int g=1;g*g<=x;g++)
            if(x%g==0)
            {
                int abc=x/g+d;
                int ab;
                if(abc%c==0)
                {
                    ab=abc/c;
                    if(ab==1)
                        ans++;
                    else
                        ans+=1<<dv[ab];
                }
                if(g*g!=x)
                {
                    abc=g+d;
                    if(abc%c==0)
                    {
                        ab=abc/c;
                        if(ab==1)
                            ans++;
                        else
                            ans+=1<<dv[ab];
                    }
                }
            }
        printf("%lld\n",ans);
    }
}