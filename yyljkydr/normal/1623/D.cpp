#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6,P=1e9+7;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int T;

int n,m,a,b,c,d,p;

int pr[N],nd;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c,&d,&p);
        nd=0;
        p=p*qpow(100,P-2)%P;
        int x=a,y=b,dx=1,dy=1;
        if(x-dx<1)
            dx=-1;
        if(y-dy<1)
            dy=-1;
        int ox=dx,oy=dy;
        do
        {
            ++nd;
            pr[nd]=(P+1-(x==c||y==d)*p)%P;
            if(x+dx>n||x+dx<1)
                dx*=-1;
            if(y+dy>m||y+dy<1)
                dy*=-1;
            x+=dx,y+=dy;
        }while(x!=a||y!=b||dx!=ox||dy!=oy);
        int k=1,b=0;
        for(int i=nd;i>=1;i--)
        {
            b++;
            k=k*pr[i]%P;
            b=b*pr[i]%P;
        }
        printf("%lld\n",b*qpow(P+1-k,P-2)%P);
    }
}