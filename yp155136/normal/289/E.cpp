#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6 + 6;

int m[N];

int high_bit(int x)
{
    int ret=0;
    for (int i=0;24>i;i++)
    {
        if (((1<<i)&x) != 0) ret = (1<<i);
    }
    return ret-1 + ret;
}

int main ()
{
    memset(m,-1,sizeof(m));
    int n;
    scanf("%d",&n);
    for (int i=n;i>=1;i--)
    {
        if (m[i] != -1) continue;
        int mask = high_bit(i);
        int mm = (mask ^ i);
        m[i] = mm;
        m[ mm ] = i;
    }
    long long ans=0;
    for (int i=0;n>=i;i++)
    {
        if (m[i] == -1) m[i] = 0;
        ans += (m[i] ^ i);
    }
    printf("%lld\n",ans);
    for (int i=0;n>=i;i++)
    {
        if(i) printf(" ");
        printf("%d",m[i]);
    }
    puts("");
}