#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    int last = -1;
    int tmp = 0;
    int ans = 0;
    for (int i=1;i<=n;++i)
    {
        int a;
        scanf("%d",&a);
        if (last == -1)
        {
            tmp = 1;
            ans = 1;
        }
        else
        {
            if (a <= last*2)
            {
                ++tmp;
            }
            else
            {
                tmp = 1;
            }
        }
        last = a;
        ans = max(ans,tmp);
    }
    printf("%d\n",ans);
}