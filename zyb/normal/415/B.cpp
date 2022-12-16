#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

long long aa[100100] ;
int main()
{
    long long n,a,b  ;
    while(cin>>n>>a>>b)
    {
        for(int i = 1 ; i <= n ; i++)
            cin>>aa[i] ;
        for(int i = 1 ; i <= n ; i++)
            cout<<aa[i]*a%b/a<<" " ;
        cout<<endl ;
    }
    return 0 ;
}