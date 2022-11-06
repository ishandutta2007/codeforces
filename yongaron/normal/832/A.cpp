#include <iostream>

using namespace std;

long long k, n, x;

int main()
{
    cin>>k;
    cin>>n;
    x = k/n;
    if(x%2 == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}