#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.precision(10);
    cout<<fixed;
    long long a, b;
    long double x;
    cin>>a>>b;
    if(b>a)
    {
        cout<<-1;
        return 0;
    }
    long long s=a/b;
    if(a%b==0)
    {
        if((a/b)%2==1)
        {
            cout<<b;
            return 0;
        }
    }
    if(s%2==1)
    {
        x=(long double)(a+b)/(long double)(s+1);
    }
    else
    {
        x=(long double)(a+b)/(long double)s;
    }
    cout<<x;
    return 0;
}