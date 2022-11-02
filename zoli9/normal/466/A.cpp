#include <iostream>
using namespace std;
int n, m, a, b;
int main()
{
    cin>>n>>m>>a>>b;
    int d=n*a;
    if(n%m==0)
    {
        d=min(d, (n/m)*b);
    }
    else
    {
        d=min(d, (n/m)*b+(n%m)*a);
        d=min(d, ((n/m)+1)*b);
    }
    cout<<d;
    return 0;
}