#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL,LL> > p;

const LL inf=5e16;

LL dis(LL x1,LL y1,LL x2,LL y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int main()  {
    LL x0,y0,ax,ay,bx,by;
    LL xs,ys,t;
    scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
    scanf("%lld%lld%lld",&xs,&ys,&t);
    for (int i=0;i<60;++i)  {
        p.push_back(make_pair(x0,y0));
        x0=ax*x0+bx;
        y0=ay*y0+by;
        if (x0>inf||y0>inf) break;
    }

    int ans=0;
    for (int i=0;i<p.size();++i)    {
        LL dt=dis(xs,ys,p[i].first,p[i].second);
        if (dt>t) continue;
        int cnt=1;
        for (int j=i-1;j>=0;--j)  {
            dt+=dis(p[j].first,p[j].second,p[j+1].first,p[j+1].second);
            if (dt>t) break;
            ++cnt;
        }
        ans=max(ans,cnt);
    }

    for (int i=0;i<p.size();++i)    {
        LL dt=dis(xs,ys,p[i].first,p[i].second);
        if (dt>t) continue;
        int cnt=1;
        for (int j=i+1;j<p.size();++j)  {
            dt+=dis(p[j].first,p[j].second,p[j-1].first,p[j-1].second);
            if (dt>t) break;
            ++cnt;
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}