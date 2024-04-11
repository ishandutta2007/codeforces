#include<bits/stdc++.h>
using namespace std;

int T,l,r;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        if(r>=l*2)
            printf("%d %d\n",l,l*2);
        else
            puts("-1 -1");
    }
}