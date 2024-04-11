#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int h[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)
            puts("Bob");
        else if((n&(n-1))==0)
        {
            //n == 2^k
            int cnt=0;
            while(n%2==0)
                n/=2,cnt++;
            if(cnt%2==1)
                puts("Bob");
            else
                puts("Alice");
        }
        else
        {
            if(n%2==1)
                puts("Bob");
            else
                puts("Alice");
        }
    }
}