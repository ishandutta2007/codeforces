#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>

using namespace std ;

int b[1100] ;
int a[1100] ;
int main()
{
    int n,m ;
    while (~scanf("%d %d",&n,&m))
    {
        for(int i = 1 ; i <= m ; i++)
            scanf("%d",&b[i]) ;
            memset(a,0,sizeof(a)) ;
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = b[i] ; j <= n ; j++)
            {
                if(a[j] == 0)
                a[j] = b[i] ;
            }
        }
        for(int i = 1 ; i < n ; i++)
            printf("%d ",a[i]) ;
        printf("%d\n",a[n]) ;
    }
    return 0 ;
}