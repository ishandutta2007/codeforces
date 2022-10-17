#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n<k)
            printf("%d\n",k-n);
        else
        {
            printf("%d\n",(n&1)^(k&1));
        }
    }
}