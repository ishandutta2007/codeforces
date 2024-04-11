#include <stdio.h>
#include <string.h>

using namespace std ;

int main()
{
    int n , k;
    while(~scanf("%d %d",&n,&k))
    {
        if(k < n/2 || (n < 2 && k != 0))
        {
            printf("-1\n") ;
            continue ;
        }
        else if(k == n/2)
        {
            for(int i = 1 ; i < n ; i++)
                printf("%d ",i) ;
            printf("%d\n",n) ;
        }
        else
        {
            int flag[21] ;
            memset(flag,0,sizeof(flag));
            int x = k-n/2+1 ;
            printf("%d %d ",x,x*2) ;
            for(int i = x*2+1 ; i <= x*2+n-2 ; i++)
                printf("%d ",i) ;
            puts("") ;
        }
    }
    return 0 ;
}