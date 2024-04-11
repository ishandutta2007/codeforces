#include <iostream>
using namespace std;
long long fib[62];
int fibo(long long x)
{
    if(x==55) return 0;
    fib[x]=fib[x-1]+fib[x-2];
    fibo(x+1);
    return 0;
}
long long n, k;
long long n2;
int main()
{
    fib[1]=1;
    fib[2]=2;
    fibo(3);
    cin>>n>>k;
    n2=n;
    while(k>1)
    {
        if(k<=fib[n2-1])
        {
            cout<<n-n2+1<<" ";
            n2-=1;
        }
        else
        {
            cout<<n-n2+2<<" "<<n-n2+1<<" ";
            k-=fib[n2-1];
            n2-=2;
        }
    }
    for(int i=n-n2+1; i<=n; i++)
    {
        cout<<i<<" ";
    }
    return 0;
}