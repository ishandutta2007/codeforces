#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1e5+10,LG=40;

int n,a[N],b[N];
i64 t;
db p[N],v;

struct Mat{
    int n,m;db a[3][3];
    Mat(int n=0,int m=0):n(n),m(m) {memset(a,0,sizeof(a));}
    db* operator [](int x) {return a[x];}
    const db* operator [](int x) const{return a[x];}
    Mat operator * (const Mat &b){
        Mat ret(n,b.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<m;k++)
                    ret[i][j]+=(*this)[i][k]*b[k][j];
        return ret;
    }
};

struct Line{db k,b;}l[N],cv[N];
int tp;
inline int sign(db v){
    static const db eps=1e-12;
    return fabs(v)<eps?0:(v>0?1:-1);
}
inline db intersect(Line a,Line b){
    return (a.b-b.b)/(b.k-a.k);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),t=rdi64();
    for(int i=1;i<=n;i++){
        scanf("%d%d%lf",&a[i],&b[i],&p[i]);
        v=max(v,p[i]*b[i]),l[i]={p[i],p[i]*a[i]};
    }
    sort(l+1,l+n+1,[&](Line a,Line b){
        return sign(a.k-b.k)!=0?a.k<b.k:a.b>b.b;
    });
    for(int i=1;i<=n;i++){
        if(i>1&&sign(l[i].k-l[i-1].k)==0) continue;
        while(tp>1&&intersect(cv[tp],l[i])<=intersect(cv[tp-1],l[i])) --tp;
        cv[++tp]=l[i];
    }
    i64 nw=0;
    Mat cur(1,3);
    cur[0][0]=0,cur[0][1]=0,cur[0][2]=1;
    for(int i=1;i<=tp;i++){
        db pos=nw*v-cur[0][0];
        while(i<tp&&pos>=intersect(cv[i],cv[i+1])) ++i;
        static Mat g[LG];
        g[0]=Mat(3,3);
        g[0][0][0]=1-cv[i].k,g[0][0][1]=0,g[0][0][2]=0;
        g[0][1][0]=cv[i].k*v,g[0][1][1]=1,g[0][1][2]=0;
        g[0][2][0]=cv[i].b,  g[0][2][1]=1,g[0][2][2]=1;
        for(int i=1;i<LG;i++) g[i]=g[i-1]*g[i-1];
        for(int j=LG-1;j>=0;j--){
            if(nw+(1ll<<j)>=t) continue;
            Mat nxt=cur*g[j];i64 nxtt=nw+(1ll<<j);
            if(i==tp||nxtt*v-nxt[0][0]<=intersect(cv[i],cv[i+1])) cur=nxt,nw=nxtt;
        }
        cur=cur*g[0],++nw;
        if(nw==t) break;
    }
    printf("%.8lf\n",cur[0][0]);
    return 0;
}