#include<bits/stdc++.h>

using namespace std;

int n,a,b;

int main()
{
    scanf("%d",&n);
    a=0;b=0;
    for (int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if (x>0) a++; else b++;
    }
    if (a>1&&b>1) puts("No\n"); else puts("Yes\n");
    return 0;
}