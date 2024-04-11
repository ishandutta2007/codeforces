#include<bits/stdc++.h>
#define maxn 10050
using namespace std;
typedef long long LL;

const double eps=1e-7;

struct node {
    LL x,y;
    double an;
    node (LL _x=0,LL _y=0)  {
        x=_x,y=_y;
        an=atan2(y,x);
    }
    node operator - (const node& N) const   {
        return node(N.x-x,N.y-y);
    }
    LL operator * (const node& N) const {
        return x*N.y-y*N.x;
    }
    bool operator < (const node& N) const   {
        if (abs(an-N.an)>eps) return an<N.an;
        return *this*N>=0;
    }

} P[maxn],Q[maxn];

int n;

LL C3(LL x) {
    return x*(x-1)*(x-2)/6;
}
LL C4(LL x) {
    return x*(x-1)*(x-2)*(x-3)/24;
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld%lld",&P[i].x,&P[i].y);
    
    LL ans=C4(n-1)*n,res=ans;
    for (int i=1;i<=n;++i)  {
        int m=0;
        for (int j=1;j<=n;++j)
            if (i!=j)
                Q[++m]=P[j]-P[i];
        sort(Q+1,Q+m+1);
        for (int j=1;j<=m;++j)
            Q[j+m]=Q[j];

        for (int j=1,k=2;j<=m;++j)  {
            LL tmp=0;
            for (;k<j+m&&Q[j]*Q[k]>=0;++k);
            tmp+=C3(k-j-1);
            ans-=tmp;
        }
    }
    printf("%lld\n",ans);
    // cout<<"res:"<<res<<endl;
    return 0;
}