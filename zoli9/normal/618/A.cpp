#include <bits/stdc++.h>
using namespace std;
long long n;
long long hatvany[21];
int f(long long x)
{
    if(x==0) return 0;
    long long u=0;
    while(hatvany[u]<=x)
    {
        u++;
    }
    u--;
    cout<<u+1<<" ";
    f(x-hatvany[u]);
    return 0;
}
int main()
{
    cin>>n;
    hatvany[0]=1;
    for(long long i=1; i<=20; i++)
    {
        hatvany[i]=hatvany[i-1]*2;
    }
    f(n);
    return 0;
}