#include <iostream>
#include <cmath>
using namespace std;
int a, b, c;
int main()
{
    cin>>a>>b>>c;
    a=abs(a);
    b=abs(b);
    if((a+b)%2!=c%2)
    {
        cout<<"No";
        return 0;
    }
    if(c<a+b)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;
}