#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    if(n%2==0) cout<<n/2;
    if(n%2==1) cout<<-(n+1)/2;
    return 0;
}