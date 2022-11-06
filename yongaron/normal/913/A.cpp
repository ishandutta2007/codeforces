#include <iostream>

using namespace std;

int m, n;

int main()
{
    cin>>n>>m;
    if(n > 26)
    {
        cout<<m<<endl;
        return 0;
    }
    int p = 1;
    for(int i = 0; i < n; i++)
        p *= 2;
    cout<<m%p<<endl;
    return 0;
}