#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n<=k)
            printf("%d\n",(k+n-1)/n);
        else if(n%k!=0)
            printf("2\n");
        else
            printf("1\n");
    }
    
}