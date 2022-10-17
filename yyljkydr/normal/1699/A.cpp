#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n&1)
            puts("-1");
        else
            printf("%d 0 0\n",n>>1);
    }

}