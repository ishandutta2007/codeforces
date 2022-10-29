#include <bits/stdc++.h>
using namespace std;

int Ask(int val)
{
    printf("%d\n",val);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if (!x) exit(0);
    return x;
}

int p[32];

int main ()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for (int i=0;n>i;i++)
    {
        int ret = Ask(1);
        if (ret == 1) p[i] = 1;
        else p[i] = 0;
    }
    int L=2,R=m;
    int now=0;
    while (L <= R)
    {
        int mid=(L+R)>>1;
        int ret = Ask(mid);
        if (!p[now]) ret = -ret;
        now = (now+1)%n;
        if (ret == 1) L = mid+1;
        else if (ret == -1)R = mid-1;
    }
}