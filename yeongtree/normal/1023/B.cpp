#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int n,k; cin>>n>>k;
    long long int x=max(1ll,k-n);
    long long int y=(k-1ll)/2ll;
    cout<<max(0ll,y-x+1ll);
    return 0;
}