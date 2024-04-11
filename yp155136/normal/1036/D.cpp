#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 300006;

int a[N],b[N];

int main ()
{
    int n;
    scanf("%d",&n);
    LL sum=0;
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int m;
    scanf("%d",&m);
    for (int j=1;j<=m;++j)
    {
        scanf("%d",&b[j]);
        sum -= b[j];
    }
    if (sum != 0)
    {
        puts("-1");
        return 0;
    }
    int ans=0;
    int ptr = 1;
    LL pre = 0;
    LL tmp=0;
    for (int i=1;i<=n;++i)
    {
        pre += a[i];
        while (tmp < pre)
        {
            tmp += b[ptr];
            ++ptr;
        }
        if (tmp == pre)
        {
            tmp = 0;
            pre = 0;
            ++ans;
        }
        //cout << "u = " << i << " , tmp = " << tmp << " , pre = " << pre << endl;
    }
    printf("%d\n",ans);
}