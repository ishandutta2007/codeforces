#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    int ret=1;
    while (x)
    {
        if (x%10) ret *= (x%10);
        x/=10;
    }
    return ret;
}

int g(int x)
{
    if (x<10) return x;
    else return g(f(x));
}

const int N = 1000001;
const int K = 10;

int a[N];
int pre[K][N];

int main ()
{
    for (int i=1;N>i;i++)
    {
        a[i] = g(i);
    }
    for (int i=1;K>i;i++)
    {
        for (int j=1;N>j;j++)
        {
            pre[i][j] = pre[i][j-1] + (a[j]==i);
        }
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        printf("%d\n",pre[k][r] - pre[k][l-1]);
    }
}