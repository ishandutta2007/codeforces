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

const int M=6e5;
int n, a[M], d[M], ps[M], p[M][10], u[M], c[M];
void add(int x, int z)
{
    int n=ps[x], m=1<<n;
    for (int ms=0;ms<m;++ms)
    {
        int t=1;
        for (int i=0;i<n;++i) if (ms&(1<<i)) t*=p[x][i];
        c[t]+=z;
    }
}
int gt(int x)
{
    int n=ps[x], m=1<<n;
    int rs=0;
    // cerr<<"--------------"<<endl; 
    for (int ms=1;ms<m;++ms)
    {
        int t=1, s=-1;
        for (int i=0;i<n;++i) if (ms&(1<<i))
        {
            s=-s;
            t*=p[x][i];
        }
        // cerr<<t<<endl;
        rs+=c[t]*s;
    }
    // cerr<<c[1]<<" "<<rs<<endl;
    return c[1]-rs;
}
int main()
{
    for (int i=2;i<M;++i)
    {
        if (d[i]==0)
        {
            d[i]=i;
            for (ll j=i*1LL*i;j<M;j+=i) d[j]=i;
        }
        // cerr<<i<<endl;
        int j=i;
        while (j>1)
        {
            int z=d[j];
            p[i][ps[i]++]=z;
            while (j%z==0) j/=z;
        }
    }
    int q;
    scanf("%d %d", &n, &q);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    ll rs=0;
    for (int i=0;i<q;++i)
    {
        int j; scanf("%d", &j); --j;
        if (u[j])
        {
            add(a[j], -1);
            rs-=gt(a[j]);
            u[j]=0;
        }
        else
        {
            rs+=gt(a[j]);
            add(a[j], 1);
            u[j]=1;
        }
        cout<<rs<<"\n";
    }
    return 0;
}