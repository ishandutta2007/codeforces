#include <iostream>

using namespace std;

int main()
{
    long long int n,k; cin>>n>>k;
    while(k--)
    {
        long long int x,y; cin>>x>>y;
        long long int a=(x-1ll)*n+y+((x+y)%2ll)*n*n;
        cout<<(a+1ll)/2ll<<endl;
    }
    return 0;
}