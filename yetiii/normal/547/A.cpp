//
//         ."".    ."",
//         |  |   /  /
//         |  |  /  /
//         |  | /  /
//         |  |/  ;-._ 
//         }  ` _/  / ;
//         |  /` ) /  /
//         | /  /_/\_/\
//         |/  /      |
//         (  ' \ '-  |
//          \    `.  /
//           |      |
//           |      |
//

#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <string>
#include <numeric>
#include <memory.h>
using namespace std;
typedef long long ll;

const int M=3e6;
int w[2][2];
ll gcde(ll a, ll b, ll &r1, ll &q1)
{
    r1=1; q1=0;
    ll r2=0, q2=1;
    while (b)
    {
        ll q=a/b;
        a-=b*q; swap(a, b);
        r1-=r2*q; swap(r1, r2);
        q1-=q2*q; swap(q1, q2);
    }
    return a;
}
ll gt(ll t, ll m)
{
    ll k=-t/m;
    while (t+(k-1)*m>=0) --k;
    while (t+k*m<0) ++k;
    return k;
}
int H[2], A[2], X[2], Y[2], m;
ll slv()
{
    ll rs=1;
    memset(w, -1, sizeof(w));
    for (int it=0;it<2;++it)
    {
        int h=H[it], a=A[it], x=X[it], y=Y[it], c=0;
        for (int hh=0;hh<M;++hh)
        {
            if (h==a)
            {
                w[it][c++]=hh;
                if (c==2) break;
            }
            h=(x*1LL*h+y)%m;
        }
    }
    int ok=2;
    if (w[0][0]==-1||w[1][0]==-1) ok=0;
    for (int it=0;it<2;++it)
    {
        if (w[0][1]==-1)
        {
            if (w[1][1]==-1)
            {
                if (w[0][0]==w[1][0])
                {
                    rs=w[0][0];
                    ok=1;
                }
                else ok=0;
            }
            else
            {
                int a=w[1][0], b=w[1][1]-w[1][0];
                if (w[0][0]>=a&&(w[0][0]-a)%b==0)
                {
                    rs=w[0][0];
                    ok=1;
                }
                else ok=0;
            }
        }
        swap(w[0][0], w[1][0]);
        swap(w[0][1], w[1][1]);
    }
    if (ok==1)
    {
        return rs;
    }
    if (w[0][0]==w[1][0]) rs=w[0][0];
    else if (ok)
    {
        ll t1, t2;
        ll a1=w[0][0], b1=w[0][1]-w[0][0];
        ll a2=w[1][0], b2=w[1][1]-w[1][0];
        if (a1>a2) swap(a1, a2), swap(b1, b2);
        ll g=gcde(b1, -b2, t1, t2);
        if (g<0) g=-g,t1=-t1,t2=-t2;
        cerr<<a1<<" "<<b1<<endl;
        cerr<<a2<<" "<<b2<<endl;
        cerr<<t1<<" "<<t2<<endl;
        cerr<<g<<endl;
        if ((a2-a1)%g) ok=0;
        else
        {
            ll sk=(a2-a1)/g;
            t1*=sk;
            t2*=sk;
            ll m1=b2/g;
            ll m2=b1/g;
            rs=0;
            ll k1=gt(t1, m1);
            ll k2=gt(t2, m2);
            ll k=max(k1, k2);
            t1+=m1*k;
            t2+=m2*k;
            cerr<<"K"<<k<<endl;
            rs=max(rs, a1+b1*1LL*t1);
            rs=max(rs, a2+b2*1LL*t2);
        }
    }
    if (!ok) rs=-1;
    return rs;
}
int br()
{
    int t=0, h[2]={H[0], H[1]};
    for (int zz=0;zz<m*m*20;++zz)
    {
        if (h[0]==A[0]&&h[1]==A[1]) return t;
        ++t;
        for (int i=0;i<2;++i)
            h[i]=(X[i]*1LL*h[i]+Y[i])%m;

    }
    return -1;
}
void tst()
{
    while (1)
    {
        m=2+rand()%10;
        for (int i=0;i<2;++i)
        {
            H[i]=rand()%m; A[i]=rand()%m;
            X[i]=rand()%m; Y[i]=rand()%m;
        }
        if (slv()!=br())
        {
            cout<<m<<endl;
            for (int i=0;i<2;++i)
            {
                cout<<H[i]<<" "<<A[i]<<" "<<X[i]<<" "<<Y[i]<<endl;
            }
            throw;
        }
    }
}
int main()
{
    // tst();
    scanf("%d", &m);
    for (int i=0;i<2;++i)
    {
        scanf("%d %d %d %d", H+i, A+i, X+i, Y+i);
    }
    cout<<slv()<<endl;
    // cout<<br()<<endl;
    return 0;
}