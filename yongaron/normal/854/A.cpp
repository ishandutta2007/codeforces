#include <iostream>

using namespace std;

int euclid(int a, int b);

int main()
{
    int x, y;
    int n;
    cin>>n;
    for(int i = 1; i < n-i; i++)
    {
        if(euclid(i, n-i) == 1)
        {
            x = i;
            y = n-i;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
int euclid(int a, int b)
{
    while(a && b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a+b;
}