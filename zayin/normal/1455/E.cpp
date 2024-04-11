#include<bits/stdc++.h>
#define maxn 10
using namespace std;
typedef long long LL;

int n=4,pos[maxn];
struct node {
    LL x,y;
} P[maxn];

LL max(LL a,LL b,LL c)  {
    return max(a,max(b,c));
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        for (int i=0;i<n;++i)
            scanf("%lld%lld",&P[i].x,&P[i].y),pos[i]=i;
        
        LL ans=1e18;
        do {
            #define LD P[pos[0]]
            #define LU P[pos[1]]
            #define RU P[pos[2]]
            #define RD P[pos[3]]

            LL lx1=min(LD.x,LU.x),rx1=max(LD.x,LU.x);
            LL lx2=min(RD.x,RU.x),rx2=max(RD.x,RU.x);
            LL ly1=min(LD.y,RD.y),ry1=max(LD.y,RD.y);
            LL ly2=min(LU.y,RU.y),ry2=max(LU.y,RU.y);

            LL res=rx1+rx2+ry1+ry2-lx1-lx2-ly1-ly2;
            
            LL xl,xr,yl,yr;
            if (rx1<lx2)
                xl=lx2-rx1,xr=rx2-lx1;
            else
            if (rx2<lx1)
                xl=lx1-rx2,xr=rx1-lx2;
            else
                xl=0,xr=max(rx2-lx1,rx1-lx2);

            if (ry1<ly2)
                yl=ly2-ry1,yr=ry2-ly1;
            else
            if (ry2<ly1)
                yl=ly1-ry2,yr=ry1-ly2;
            else
                yl=0,yr=max(ry2-ly1,ry1-ly2);

            // for (int i=0;i<n;++i)
            //     cout<<i<<":"<<P[pos[i]].x<<" "<<P[pos[i]].y<<endl;
            // cout<<"x1:"<<lx1<<" "<<rx1<<endl;
            // cout<<"x2:"<<lx2<<" "<<rx2<<endl;
            // cout<<"y1:"<<ly1<<" "<<ry1<<endl;
            // cout<<"y2:"<<ly2<<" "<<ry2<<endl;
            // cout<<xl<<" "<<xr<<" | "<<yl<<" "<<yr<<endl;
            if (yr<xl)
                res+=2*(xl-yr);
            else
            if (xr<yl)
                res+=2*(yl-xr);

            ans=min(ans,res);

            // for (int i=0;i<n;++i) cout<<pos[i]<<" "; cout<<" ~ "<<res<<endl;

        } while (next_permutation(pos,pos+n));
        printf("%lld\n",ans);
    }
    return 0;
}