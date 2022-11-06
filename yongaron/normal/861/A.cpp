#include <iostream>

using namespace std;

long long n, k, x, y;
int f = 0, t = 0;
long long a;

int main()
{
    cin>>n>>k;
    y = n;
    while(!(n%2))
    {
        t++;
        n /= 2;
    }
    while(!(n%5))
    {
        f++;
        n /= 5;
    }
    x = 1;
    for(int i = 0; i < max(k-t, (long long)0); i++)
        x*=2;
    for(int i = 0; i < max(k-f, (long long)0); i++)
        x*=5;
    a = y*x;
    cout<<a<<endl;
    return 0;
}