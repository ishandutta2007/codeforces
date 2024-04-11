#include <iostream>

using namespace std;

int a, b, k;

int main()
{
    cin>>a>>b>>k;
    a %= b;
    bool ok = false;
    int i;
    for(i = 0; i < 1000000; i++)
    {
        a *= 10;
        int x = a/b;
        a %= b;
        if(x == k)
        {
            ok = true;
            break;
        }
    }
    if(ok)
        cout<<i+1<<endl;
    else
        cout<<-1<<endl;
    return 0;
}