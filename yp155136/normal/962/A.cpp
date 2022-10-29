#include <bits/stdc++.h>
using namespace std;

int a[200006];

int main ()
{
    int n;
    scanf("%d",&n);
    int tot=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        tot += a[i];
    }
    int need = (tot+1)/2;
    int pre=0;
    for (int i=1;n>=i;i++)
    {
        pre += a[i];
        if (pre >= need)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}