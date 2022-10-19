#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

long long a,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        /*
        2x+y<=a
        2y+x<=b
        maximize x+y
        */
        scanf("%lld%lld",&a,&b);
        if(a>b)
            swap(a,b);
        if(b>=a*2)
            printf("%lld\n",a);
        else
        {
            //x-y=a-b
            //x+y=(a+b)/3
            printf("%lld\n",(a+b)/3);
        }
    }
}