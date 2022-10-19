#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int s=0;
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
            s^=a[i];
        if(s)
        {
            puts("NO");
            return 0;
        }
        n--;
    }
    puts("YES");
    printf("%d\n",n-1);
    for(int i=1;i<=n/2;i++)
        printf("%d %d %d\n",1,i*2,i*2+1);
    for(int i=1;i<=n/2;i++)
        printf("%d %d %d\n",1,i*2,i*2+1);
}