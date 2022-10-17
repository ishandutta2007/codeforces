#include<bits/stdc++.h>
using namespace std;

int T;

int n,k,now;

int query(int x)
{
    printf("%d\n",now^x);
    fflush(stdout);
    now^=(now^x);
    int ret=0;
    scanf("%d",&ret);
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        now=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            if(query(i))
                break;
    }
}