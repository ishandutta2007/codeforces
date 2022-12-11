#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int maxn=(int) 1e5+20;

inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

bool f[maxn],vis[maxn];
int p[maxn];
int n;

int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) { p[i]=read(); vis[i]=0; }
        bool judge=0;
        int x,y;
        for(int i=1;i<=n;i++) if(i==p[i])
        {
            judge=1;
            x=i;
            break;
        }
        if(judge)
        {
            puts("YES");
            for(int i=1;i<=n;i++) if(i^x)
                printf("%d %d\n",x,i);
            continue;
        }
        int a,b;
        bool good=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int len=1,x=i;
                vis[x]=1;
                while(p[x]!=i)
                {
                    x=p[x];
                    vis[x]=1;
                    f[x]=len&1;
                    len++;
                }
                if(len&1)
                {
                    puts("NO");
                    return 0;
                }
                if(len==2)
                {
                    good=1;
                    a=i;
                    b=p[i];
                }
            }
        }
        if(!good)
        {
            puts("NO");
            return 0;
        }
        puts("YES");
        printf("%d %d\n",a,b);
        for(int i=1;i<=n;i++)
        {
            if(i==a || i==b) continue;
            else if(f[i]) printf("%d %d\n",i,b);
            else printf("%d %d\n",i,a);
        }
    }
    return 0;
}