#include<bits/stdc++.h>

using namespace std;

int a,b,c,n;

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    a%=b;
    for (int i=1;i<=b;i++)
    {
        a=a*10;
        if (a/b==c) {printf("%d\n",i); return 0;}
        a%=b;
    }
    printf("-1\n");return 0;
}