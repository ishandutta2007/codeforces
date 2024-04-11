#include<bits/stdc++.h>
using namespace std;

int T,n,m,a,b,c,d;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
        int ansx=c>=a?c-a:n-c+n-a;
        int ansy=d>=b?d-b:m-d+m-b;
        printf("%d\n",min(ansx,ansy));
    }
}