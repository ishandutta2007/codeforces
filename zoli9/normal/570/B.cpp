#include <iostream>
using namespace std;
long long n, m;
int main()
{
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n-m>m-1)
    {
        cout<<m+1;
        return 0;
    }
    cout<<m-1;
    return 0;
}