#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+1e3+7,INF=1e18;

int n;

char s[N];

struct P{
    int x,y;
}p[N];

int mnx,mxx,mny,mxy,mnyx,mxyx;

bool chk(int d)
{
    mnx=mny=0;mnyx=-INF;
    mxx=mxy=mxyx=INF;
    for(int i=1;i<=n;i++)
    {
        mnx=max(mnx,p[i].x-d);
        mny=max(mny,p[i].y-d);
        mnyx=max(mnyx,p[i].y-p[i].x-d);
        mxx=min(mxx,p[i].x+d);
        mxy=min(mxy,p[i].y+d);
        mxyx=min(mxyx,p[i].y-p[i].x+d);
    }
    if(mnx>mxx||mny>mxy||mnyx>mxyx||mxy-mnx<mnyx||mny-mxx>mxyx)
        return 0;
    int c=(mnx==0&&mxx==0)+(mny==0&&mxy==0)+(mnyx==0&&mxyx==0);
    if(c>=2)
        return 0;
    return 1;
}

void gen(int &x,int &y)
{
    for(int i=mnx;i<=mxx;i++)
    {
        int lb=mny,rb=mxy;
        if(!i&&!lb)
            lb++;
        //mxyx>=y-i>=mnyx
        lb=max(lb,mnyx+i);
        rb=min(rb,mxyx+i);
        if(lb>rb)
            continue;
        x=i,y=lb;
        return;
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int j=1;j<=len;j++)
            p[i].x+=s[j]=='B';
        p[i].y=len-p[i].x;
    }
    int l=-1,r=2e6;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(chk(mid))
            r=mid;
        else
            l=mid;
    }
    chk(r);
    int ansx=0,ansy=0;
    gen(ansx,ansy);
    printf("%lld\n",r);
    for(int i=0;i<ansx+ansy;i++)
        putchar(i<ansx?'B':'N');
    puts("");
}