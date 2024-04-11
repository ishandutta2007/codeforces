#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m;

int query(int h,int w,int a,int b,int c,int d)
{
    printf("? %d %d %d %d %d %d\n",h,w,a,b,c,d);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair
typedef vector<pii> vpi;

vpi solve(int x)
{
    vpi ret;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            ret.push_back(mp(i,0));
            while(x%i==0)
                x/=i,ret.back().sd++;
        }
    if(x!=1)
        ret.push_back(mp(x,1));
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    vpi vn=solve(n),vm=solve(m);
    int sn=n;
    for(auto [x,y]:vn)
    {
        for(int j=1;j<=y;j++)
        {
            int d=x,b=sn/x,tmpn=sn;
            int ok=1;
            while(d>1)
            {
                int nd=d/2;
                if(query(b*nd,m,1,1,tmpn-b*nd+1,1))
                    d-=nd,tmpn-=nd*b;
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                sn/=x;
            else
                break;
        }
    }   
    int sm=m;
    for(auto [x,y]:vm)
    {
        for(int j=1;j<=y;j++)
        {
            int d=x,b=sm/x,tmpm=sm;
            int ok=1;
            while(d>1)
            {
                int nd=d/2;
                if(query(n,b*nd,1,1,1,tmpm-b*nd+1))
                    d-=nd,tmpm-=nd*b;
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                sm/=x;
            else
                break;
        }
    }   
    int x=0,y=0;
    for(int i=1;i<=n;i++)
        if(n%i==0&&i%sn==0)
            x++;
    for(int i=1;i<=m;i++)
        if(m%i==0&&i%sm==0)
            y++;
    printf("! %d\n",x*y);
    fflush(stdout);
}