#include <iostream>

using namespace std;

int main()
{
    int m,b; cin>>m>>b;
    long long int max_banana=0;

    for(long long int i=0;i<=b;i++)
    {
        long long int j=m*(b-i);
        max_banana=max(max_banana,(i+1)*(j+1)*(i+j)/2);
    }

    cout<<max_banana;
    return 0;
}