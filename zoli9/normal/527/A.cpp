#include <iostream>
using namespace std;
long long a, b;
long long meg(long long x, long long y)
{
    if(y==0)
    {
        return 0;
    }
    long long mar=x%y;
    long long hany=x/y;
    long long e=y;
    y=x%y;
    x=e;
    return hany+meg(x, y);
}
int main()
{
    cin>>a>>b;
    cout<<meg(a, b);
    return 0;
}