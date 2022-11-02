#include<bits/stdc++.h>
#define ALL(A)  A.begin(),A.end()
#define maxn 55
#define maxm 10
#define modu 998244353
using namespace std;
typedef long long LL;

LL inv(LL a)
{
    LL ans=1;
    for (int k=modu-2;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n,m;
int x[maxn],y[maxn];

vector<int> T;

LL calc(int T)
{
    vector<int> C,Y;
    struct node {
        int x,l,r,d;
        node(int _x,int _l,int _r,int _d)   {
            x=_x,l=_l,r=_r,d=_d;
        }
        bool operator < (const node& N) const   {
            return x<N.x;
        }
    };
    vector<node> X;
    for (int i=1;i<=n;++i)
    {
        int ly=y[i]-T,ry=y[i]+T+1;
        Y.push_back(ly);
        Y.push_back(ry);
        X.push_back(node(x[i]-T,ly,ry,1));
        X.push_back(node(x[i]+T+1,ly,ry,-1));
    }

    sort(ALL(X));
    sort(ALL(Y));
    Y.resize(unique(ALL(Y))-Y.begin());
    C.resize(Y.size(),0);

    LL ans=0;
    for (int i=0;i<X.size();++i)
    {
        int l=lower_bound(ALL(Y),X[i].l)-Y.begin(),r=lower_bound(ALL(Y),X[i].r)-Y.begin(),d=X[i].d;
        if (i)
            for (int j=0;j<Y.size();++j)
                if (C[j])
                {
                    assert(j!=Y.size()-1);
                    ans=(ans+1LL*(X[i].x-X[i-1].x)*(Y[j+1]-Y[j]))%modu;
                }
        for (int j=l;j<r;++j)
            C[j]+=d;
    }
    return ans;
}

LL X[maxm],Fx[maxm];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d%d",x+i,y+i);
    
    T.push_back(m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            int tx=abs(x[i]-x[j]),ty=abs(y[i]-y[j]),t=max((tx+1)>>1,(ty+1)>>1);
            // cout<<i<<" "<<j<<" "<<t<<endl;
            if (t>m)    continue;
            T.push_back(t);
        }
    sort(ALL(T));
    T.resize(unique(T.begin(),T.end())-T.begin());

    
    LL ans=0;
    for (int i=0;i<T.size()-1;++i)
    {
        // cout<<"time:"<<T[i]<<endl;
        if (T[i]+4>=T[i+1])
        {
            for (int t=T[i];t<T[i+1];++t)
                ans=(ans+calc(t))%modu;
        } else
        {
            for (int j=1;j<=4;++j)
                X[j]=T[i]+j-1,Fx[j]=(calc(X[j])+Fx[j-1])%modu;
            
            // for (int j=1;j<=4;++j)
            //     cout<<"("<<X[j]<<" "<<Fx[j]<<")"<<endl;
            // cout<<endl;
            
            LL sum=0,t=T[i+1]-1;
            for (int j=1;j<=4;++j)
            {
                LL p=1,q=1;
                for (int k=1;k<=4;++k)
                    if (k!=j)
                        p=p*(t-X[k]+modu)%modu,q=q*(X[j]-X[k]+modu)%modu;
                sum=(sum+p*inv(q)%modu*Fx[j])%modu;
            }
            // cout<<"sum:"<<sum<<endl;
            ans=(ans+sum)%modu;
        }
    }

    ans=(m*calc(m)-ans+modu)%modu;
    printf("%lld\n",ans);
    // cout<<"last:"<<calc(0)<<" "<<calc(15)<<" "<<calc(m)<<endl;
    return 0;
}