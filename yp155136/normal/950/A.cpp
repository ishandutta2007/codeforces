#include <iostream>
using namespace std;

int main ()
{
    int l,r,mid;
    cin >> l >> r >> mid;
    while (mid--)
    {
        if (l>r) r++;
        else l++;
    }
    cout << min(l,r)*2 << endl;
}