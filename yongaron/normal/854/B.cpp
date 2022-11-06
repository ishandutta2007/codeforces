#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int m = n/3;
    if(k == 0 || k == n)
        cout<<0<<" ";
    else
        cout<<1<<" ";
    if(k <= m)
        cout<<2*k<<endl;
    else
        cout<<n-k<<endl;
    return 0;
}