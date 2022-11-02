#include<bits/stdc++.h>
using namespace std;

int n,a,ans;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        scanf("%d",&a);
        ans+=a*i;
    }
    printf("%d\n",ans<<2);
    return 0;
}