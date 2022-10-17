#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e2+1e1+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

struct P{
    int x,y;
}p[N];

P operator -(const P &a,const P &b)
{
    return {a.x-b.x,a.y-b.y};
}

int operator *(const P &a,const P &b)
{
    return a.x*b.y-a.y*b.x;
}

int n,k;

pii f[N][N];

bool chk(int s)
{
    for(int len=3;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            f[i][j]=mp(-1,-1);
            for(int k=i+1;k<j;k++)
            {
                int nx=f[i][k].fs+f[k][j].fs;
                int ny=f[i][k].sd+f[k][j].sd+abs((p[i]-p[j])*(p[k]-p[j]));
                if(ny>=s)
                    nx++,ny=0;
                f[i][j]=max(f[i][j],{nx,ny});
            }
        }
    }
    return f[1][n].fs>=k+1;
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y);
    int l=0,r=1e17;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(chk(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%lld\n",l);
}