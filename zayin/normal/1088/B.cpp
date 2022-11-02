#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;
int a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    
    int i=1;

    while (m--)
    {
        while (i<=n&&a[i]==a[i-1])    ++i;
        if (i<=n)
            printf("%d\n",a[i]-a[i-1]),++i;
        else
            printf("0\n");
    }
    return 0;
}