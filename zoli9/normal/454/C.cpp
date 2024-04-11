#include <bits/stdc++.h>
using namespace std;
long long n, m;
long double legfeljebb[100009];
long double legalabb[100009];
long double w;
long double power(long double x, long long n)
{
    long double ans=(long double)1;
    while(n>0)
    {
        if(n%2)
        {
            ans*=x;
        }
        x*=x;
        n/=2;
    }
    return ans;
}
int main()
{
    cin>>m>>n;
    w=0;
    for(int i=1; i<=m; i++)
    {
        legfeljebb[i]=power((long double)(i-1)/m, n);
        legalabb[i]=1-legfeljebb[i];
        w+=legalabb[i];
    }
    cout<<w;
    return 0;
}