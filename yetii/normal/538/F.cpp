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
#include <numeric>
using namespace std;
typedef long long ll;

const int N=2*1000*100+10, M=6000000;
struct Q
{
    int r, k, s, i;
} q[M];
bool R(const Q &a, const Q &b)
{
    return a.r<b.r;
}
int n, a[N], X[N], xs, t[N], rs[N], qs;
void inc(int p)
{
    for (;p<N;p=p|(p+1)) ++t[p];
}
int gt(int p)
{
    int rs=0;
    for (;p>=0;p=(p&(p+1))-1) rs+=t[p];
    return rs;
}
int main()
{
    // ll rs=0;
    // for (int k=1;k<N;++k)
    // {
    //     for (int i=0;i<N;++i)
    //     {
    //         ++rs;
    //         if (i*1LL*k+1>=N) break;
    //     }
    // }
    // cout<<rs<<endl;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]),X[i]=a[i];
    sort(X, X+n); xs=unique(X, X+n)-X;
    for (int i=0;i<n;++i) a[i]=lower_bound(X, X+n, a[i])-X;
    for (int k=1;k<n;++k)
    {
        for (int i=0;i<N;++i)
        {
            ll l=k*1LL*i+1, r=l+k;
            if (l>=n) break;
            if (r>n) r=n;
            q[qs++]={int(r),a[i]-1,1,k-1};
            q[qs++]={int(l),a[i]-1,-1,k-1};
            //cerr<<l<<" "<<r<<" "<<a[i]-1<<endl;
        }
    }
    sort(q, q+qs, R);
    for (int i=0,pt=0;i<n;++i)
    {
        inc(a[i]);
        while (pt<qs&&q[pt].r<=i+1)
        {
            rs[q[pt].i]+=q[pt].s*gt(q[pt].k);
            ++pt;
        }
    }
    for (int i=0;i+1<n;++i) printf("%d ", rs[i]); puts("");
    return 0;
}