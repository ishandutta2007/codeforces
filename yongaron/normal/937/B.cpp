#include <iostream>

using namespace std;

int main()
{
    int p, y;
    cin>>p>>y;
    int x = -1;
    for(int i = y; i > y-500 && i > 1; i--)
    {
        bool ok = true;
        for(int j = 2; j <= p && j < 34000; j++)
        {
            if(i%j == 0 || p >= i)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            x = i;
            break;
        }
    }
    cout<<x<<endl;
    return 0;
}