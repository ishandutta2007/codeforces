#include<bits/stdc++.h>
using namespace std;

int T,l,r;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        if(l==r)
            puts("0");
        else
        {
            if(r<l*2)
                printf("%d\n",r%l);
            else
                printf("%d\n",(r+1)/2-1);
        }
    }
}