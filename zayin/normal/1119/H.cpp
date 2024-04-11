#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m,k,offset;
LL x,y,z;
LL X[maxn],Y[maxn],XY[maxn];
LL ans[maxn];

const LL inv2=(modu+1)>>1;
LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a=(a%modu+modu)%modu;k;k>>=1)  {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

void DFT(LL *A)    {
    for (int len=2;len<=m;len<<=1)  {
        int t=len>>1;
        for (LL *p=A;p!=A+m;p+=len)
            for (int i=0;i<t;++i)   {
                LL u=p[i],v=p[i+t];
                p[i]=(u+v)%modu;
                p[i+t]=(u-v+modu)%modu;
            }
    }
}

int main()  {
    scanf("%d%d%lld%lld%lld",&n,&k,&x,&y,&z),m=1<<k;
    for (int i=0;i<n;++i)   {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        offset^=a,b^=a,c^=a;
        ++X[b],++Y[c],++XY[b^c];
    }
    DFT(X),DFT(Y),DFT(XY);
    // cout<<"X:"; for (int i=0;i<m;++i)   cout<<X[i]<<" "; cout<<endl;
    // cout<<"Y:"; for (int i=0;i<m;++i)   cout<<Y[i]<<" "; cout<<endl;
    // cout<<"XY:"; for (int i=0;i<m;++i)   cout<<XY[i]<<" "; cout<<endl;

    for (int i=0;i<m;++i)   ans[i]=1;
    for (int fx=-1;fx<=1;fx+=2)
        for (int fy=-1;fy<=1;fy+=2) {
            for (int i=0;i<m;++i)   {
                LL c=fx*X[i]+fy*Y[i]+fx*fy*XY[i]+n;
                c=(c%modu+modu)%modu;
                // cout<<fx<<" "<<fy<<":"<<i<<" "<<c<<"("<<fx*X[i]<<" "<<fy*Y[i]<<" "<<fx*fy*XY[i]<<" "<<n<<")"<<endl;
                assert(c%4==0);
                c/=4;
                ans[i]=ans[i]*pw(x+fx*y+fy*z,c)%modu;
            }
        }
    
    DFT(ans);
    LL I=pw(m);
    for (int i=0;i<m;++i)
        printf("%lld ",ans[i^offset]*I%modu);
    return 0;
}