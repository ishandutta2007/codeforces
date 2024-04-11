#include <iostream>

using namespace std;

int n, s, d;

int main()
{
    cin>>n;
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>s>>d;
        while(s <= x)
            s += d;
        x = s;
    }
    cout<<x<<endl;
    return 0;
}