#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n%2==0)
    {
        cout<<4<<" "<<n-4;
        return 0;
    }
    cout<<9<<" "<<n-9;

    return 0;
}