#include <iostream>
#include <cstdio>
using namespace std;

int _[1000006];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int pre=0;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        pre += x;
        _[pre]++;
    }
    pre=0;
    for (int i=1;m>=i;i++)
    {
        int x;
        scanf("%d",&x);
        pre += x;
        _[pre]++;
    }
    int ans=0;
    for (int i=0;1000006>i;i++)
    {
        ans += (_[i]==2);
    }
    printf("%d\n",ans);
}