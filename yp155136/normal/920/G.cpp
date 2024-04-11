#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000006;
int u[N];
vector<int> p[N];

#define SZ(x) ((int)(x).size())

void build()
{
    for (int i=0;N>i;i++)
    {
        u[i] = 1;
    }
    for (int i=2;N>i;i++)
    {
        if (SZ(p[i]) == 0)
        {
            for (int j=i;N>j;j+=i)
            {
                p[j].push_back(i);
                if (j%(i*1LL*i) == 0) u[j] = 0;
                else u[j] *= -1;
            }
        }
    }
}

LL cal(LL x,vector<int> v)
{
    LL ret=0;
    for (int i:v)
    {
        ret += u[i]*(x/i);
    }
    return ret;
}

int main ()
{
    build();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        LL x,pp,k;
        scanf("%lld %lld %lld",&x,&pp,&k);
        vector<int> v;
        for (int mask=0;(1<<SZ(p[pp]))>mask;mask++)
        {
            int num = 1;
            for (int j=0;SZ(p[pp])>j;j++)
            {
                if (((1<<j)&mask) != 0) num *= p[pp][j];
            }
            v.push_back(num);
        }
        LL _0 = cal(x,v);
        LL L=x,R = (1LL<<30);
        while (R-L != 1)
        {
            LL mid = (L+R)>>1;
            if (cal(mid,v) - _0 >= k) R = mid;
            else L = mid;
        }
        printf("%lld\n",R);
    }
}