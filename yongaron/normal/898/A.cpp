#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m = n/10;
    m *= 10;
    if(n-m > 5)
        m += 10;
    cout<<m<<endl;
    return 0;
}