#include<stdio.h>
#define N 300005
#include<set>
#include<algorithm>
using namespace std;
struct node {
    int f[N*4];
    inline void up(int o) {
        f[o]=max(f[o*2+1],f[o*2]);
    }
    inline void change(int o,int l,int r,int ll,int p) {
        if (l==ll&&r==ll) {
            f[o]=p; return ;
        }
        int mid=(l+r)>>1;
        if (ll<=mid) change(o*2,l,mid,ll,p);
        else change(o*2+1,mid+1,r,ll,p);
        up(o);
    }
    inline int ask(int o,int l,int r,int ll,int rr) {
        if (l==ll&&r==rr) return f[o];
        int mid=(l+r)>>1;
        if (rr<=mid) return ask(o*2,l,mid,ll,rr);
        else if (ll>mid) return ask(o*2+1,mid+1,r,ll,rr);
        else return max(ask(o*2,l,mid,ll,mid),ask(o*2+1,mid+1,r,mid+1,rr));
    }
}X,Y;
int v[N],n,m,i,id,nx,ny;
struct lgs {
    int id,x,y;
}yy,Q[N];
struct syf
{
    bool operator()(const lgs &a,const lgs &b) 
    {
        return a.y<b.y;
    }
};
set<lgs,syf>x;
set<lgs,syf>::iterator gt;
struct lhy
{
    bool operator()(const lgs &a,const lgs &b) 
    {
        return a.x<b.x;
    }
};
set<lgs,lhy>y;
set<lgs,lhy>::iterator GT;
int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++) {
        scanf("%d",&id);
        if (id==1) {
            scanf("%d%d",&nx,&ny);
            int bb=1;
            ny+=m-i+1;
            
            if (x.end()!=x.begin()) {
                bb=0;
                int R=0;
                for (gt=x.begin();gt!=x.end();gt++) {
                    if ((*gt).y>ny) break;
                    if (v[(*gt).id]) Q[++R]=(*gt);
                    X.change(1,1,N-5,(*gt).x,0);
                    Y.change(1,1,N-5,(*gt).y,0);
                }
                for (int j=1;j<=R;j++) x.erase(Q[j]);
            }
            int gtw=X.ask(1,1,N-5,nx,N-5)+1;
            X.change(1,1,N-5,nx,gtw);
            Y.change(1,1,N-5,ny,gtw);
            if (!bb) {
                for (gt=x.begin();gt!=x.end();gt++) {
                    if ((*gt).y>ny) break;
                }
                if (gt!=x.begin()) {
                    gt--;
                    for (;;gt--) {
                        gtw=X.ask(1,1,N-5,(*gt).x,N-5)+1;
                        X.change(1,1,N-5,(*gt).x,gtw);
                        Y.change(1,1,N-5,(*gt).y,gtw);
                        if (gt==x.begin()) break;
                    }
                }
            }
            yy.x=nx; yy.y=ny; yy.id=i;
            x.insert(yy);
            y.insert(yy);
            printf("%d\n",X.ask(1,1,N-5,1,N-5));
        }
        else {
            scanf("%d",&nx);
            int bb=1; int yym=0;
            if (y.end()!=y.begin()) {
                bb=0;
                for (GT=y.begin();GT!=y.end();GT++) {
                    yym++;
                    if (v[(*GT).id]) {
                        y.erase(GT); continue;
                    }
                    Y.change(1,1,N-5,(*GT).y,0);
                    X.change(1,1,N-5,(*GT).x,0);
                    if (yym==nx) break;
                }
            }
            if (!bb) {
                v[(*GT).id]=1;
                yy=(*GT);
                if (yym>1) GT--,y.erase(yy);
                else {
                    y.erase(yy);
                    printf("%d\n",X.ask(1,1,N-5,1,N-5));
                    continue;
                }
                for (;;GT--) {
                    int gtw=Y.ask(1,1,N-5,(*GT).y,N-5)+1;
                    yy=(*GT);
                    X.change(1,1,N-5,(*GT).x,gtw);
                    Y.change(1,1,N-5,(*GT).y,gtw);
                    if (GT==y.begin()) break;
                }
            }
            printf("%d\n",X.ask(1,1,N-5,1,N-5));
        }
    }
}