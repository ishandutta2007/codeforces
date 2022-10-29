#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;

LL a[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
    }
    LL pre=0;
    LL idx = 0;
    for (int i=1;m>=i;i++)
    {
        LL q;
        scanf("%lld",&q);
        while (pre + a[idx+1] < q)
        {
            //cout << "idx = " << idx << endl;
            pre += a[idx+1];
            ++idx;
        }
        printf("%lld %lld\n",idx+1,q-pre);
    }
}