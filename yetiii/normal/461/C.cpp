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

const int T=1000*1000;
int n, q, a[T], l, r, inv;
void add(int p, int x)
{
    for (;p<T;p=p|(p+1)) a[p]+=x;
}
int gs(int p)
{
    int rs=0;
    for (--p;p>=0;p=(p&(p+1))-1) rs+=a[p];
    return rs;
}
int gs(int l, int r)
{
    return gs(r)-gs(l);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    r=n; for (int i=0;i<n;++i) add(i, 1);
    for (int qi=0;qi<q;++qi)
    {
        int t; scanf("%d", &t);
        int len=r-l;
        if (t==1)
        {
            int p; scanf("%d", &p);
            if (p>len/2)
            {
                inv^=1;
                p=len-p;
            }
            if (!inv)
            {
                for (int i=0;i<p;++i)
                {
                    int v=gs(l+i, l+i+1);
                    add(l+p+p-i-1, v);
                }
                l+=p;
            }
            else
            {
                for (int i=0;i<p;++i)
                {
                    int v=gs(r-i-1, r-i);
                    add(r-p-p+i, v);
                }
                r-=p;
            }
        }
        else
        {
            int L, R; scanf("%d %d", &L, &R);
            if (inv)
            {
                L=len-L; R=len-R; swap(L, R);
            }
            printf("%d\n", gs(l+L, l+R));
        }
    }
    return 0;
}