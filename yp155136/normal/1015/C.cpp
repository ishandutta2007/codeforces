#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<LL> v;
    LL sum=0;
    for (int i=1;n>=i;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        sum += a;
        v.push_back(a-b);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if (sum <= k)
    {
        puts("0");
        return 0;
    }
    for (int i=0;n>i;i++)
    {
        sum -= v[i];
        if (sum <= k)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}