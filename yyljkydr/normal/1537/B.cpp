#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,m,x,y;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        int a,b,c,d;
        if(x-1<n-x)
            a=n;
        else
            a=1;
        if(y-1<m-y)
            b=m;
        else
            b=1;
        c=n+1-a,d=m+1-b;
        printf("%d %d %d %d\n",a,b,c,d);
    }
}