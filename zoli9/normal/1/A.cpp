#include <iostream>
using namespace std;

long long n, m, a;

int main()
{

    cin>>n>>m>>a;

    n-=1;
    m-=1;
    cout<<(n/a+1)*(m/a+1);


    return 0;
}