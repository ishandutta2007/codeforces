#include <iostream>
using namespace std;

int main()
{
    cout<<1998<<endl;
    for(int i=1; i<=999; i++)
    {
        cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
    }
    for(int i=999; i>=1; i--)
    {
        cout<<i<<" "<<1<<" "<<i<<" "<<2<<endl;
    }
    return 0;
}