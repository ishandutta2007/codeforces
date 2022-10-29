#include <iostream>
using namespace std;

int main ()
{
    int x;
    cin >> x;
    if (x%10==0)
    {
        cout << x<<endl;
    }
    else if (x%10 <= 5)
    {
        cout << (x/10)*10 << endl;
    }
    else
    {
        cout << (x/10)*10+10<<endl;
    }
}