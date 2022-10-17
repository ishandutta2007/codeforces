#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll T,n;
 
int main()
{
    ll i,j;
    cin>>T;
    while(T--)
    {
        scanf("%lld",&n);
        if(n==3)
        {
        	puts("3 2 1");
        	puts("1 3 2");
        	puts("3 1 2");
        	continue;
		}
        for(i=n;i>=1;i--)
        {
        	for(j=i;j>=1;j--) printf("%lld ",j);
        	for(j=n;j>i;j--) printf("%lld ",j);
        	puts("");
		}
    }
}